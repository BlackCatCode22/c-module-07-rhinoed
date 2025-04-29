#include "Frame.h"
#include <wx/wx.h>
#include <wx/statbmp.h>
#include <fstream>
#include "Animal.h"
#include "ZooManager.h"
#include "Parser.h"
#include "Hyena.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"
#include <set>

enum
{
    ID_Hello = 1,
    ID_Hyena = 2,
    ID_Lion = 3,
    ID_Tiger = 4,
    ID_Bear = 5,
    ID_Process = 6,
    ID_GenerateReport = 7,// Add a unique ID for the generate report button
};

Frame::Frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title), zoo() {
    // Initialize zooManager::ZooManager zoo as a member variable
    // create a menu bar
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tShift+Ctrl-H",
                     "Hello, I built this GUI using wxWidgets");
    // add option to process animals
    menuFile->Append(ID_Process, "&Process Animals...\tShift+Ctrl-P",
                     "Process the incoming animals using ../arrivingAnimals.txt");
    menuFile->Append(ID_GenerateReport, "&Generate Report...\tShift+Ctrl-G","Generates a Zoo Report saving it to ../zooReport.txt");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &Frame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &Frame::processAnimals, this, ID_Process);
    Bind(wxEVT_MENU, &Frame::generateReport, this, ID_GenerateReport);
    Bind(wxEVT_MENU, &Frame::onOpenFile, this, wxID_OPEN);

    // Create a status bar
    CreateStatusBar();
    SetStatusText("Welcome to zookeeper!");

    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // Create text labels for each of the animals space them out equally across the top
    new wxStaticText(panel, wxID_ANY, "Hyenas", wxPoint(122, 112), wxSize(30, 20));
    new wxStaticText(panel, wxID_ANY, "Lions", wxPoint(321, 112), wxSize(30, 20));
    new wxStaticText(panel, wxID_ANY, "Tigers", wxPoint(518, 112), wxSize(30, 20));
    new wxStaticText(panel, wxID_ANY, "Bears", wxPoint(715, 112), wxSize(20, 20));

    // Under the labels create labels for the number of animals
    hyena_count_label = new wxStaticText(panel, wxID_ANY, "0", wxPoint(172, 112), wxSize(30, 20));
    lion_count_label = new wxStaticText(panel, wxID_ANY, "0", wxPoint(361, 112), wxSize(30, 20));
    tiger_count_label = new wxStaticText(panel, wxID_ANY, "0", wxPoint(562, 112), wxSize(30, 20));
    bear_count_label = new wxStaticText(panel, wxID_ANY, "0", wxPoint(755, 112), wxSize(30, 20));

    // list box for the animals
    hyena_list_box = new wxListBox(panel, wxID_ANY, wxPoint(12, 132), wxSize(185, 100));
    lion_list_box = new wxListBox(panel, wxID_ANY, wxPoint(209, 132), wxSize(185, 100));
    tiger_list_box = new wxListBox(panel, wxID_ANY, wxPoint(406, 132), wxSize(185, 100));
    bear_list_box = new wxListBox(panel, wxID_ANY, wxPoint(603, 132), wxSize(185, 100));

    auto processAnimalsButton = new wxButton(panel, ID_Process, "Process Animals", wxPoint(350, 238), wxSize(150, 50));
    auto generateReportButton = new wxButton(panel, ID_GenerateReport, "Generate Report", wxPoint(350, 500), wxSize(150, 50));
    auto openFileButton = new wxButton(panel, wxID_OPEN, "Open File", wxPoint(12, 238), wxSize(150, 50));

    // Bind the buttons to the corresponding functions
    Bind(wxEVT_BUTTON, &Frame::processAnimals, this, ID_Process);
    Bind(wxEVT_BUTTON, &Frame::generateReport, this, ID_GenerateReport);
    Bind(wxEVT_BUTTON, &Frame::onOpenFile, this, wxID_OPEN);
    // Create a list box to display the animals
    report_box = new wxListBox(panel, wxID_ANY, wxPoint(12, 300), wxSize(776, 200));

    // Load and display images
    wxImage::AddHandler(new wxPNGHandler);
    wxBitmap hyenaBitmap(wxT("../images/hyena.png"), wxBITMAP_TYPE_PNG);
    wxBitmap lionBitmap(wxT("../images/lion.png"), wxBITMAP_TYPE_PNG);
    wxBitmap tigerBitmap(wxT("../images/tiger.png"), wxBITMAP_TYPE_PNG);
    wxBitmap bearBitmap(wxT("../images/bear.png"), wxBITMAP_TYPE_PNG);

    new wxStaticBitmap(panel, wxID_ANY, hyenaBitmap, wxPoint(12, 32), wxSize(100, 100));
    new wxStaticBitmap(panel, wxID_ANY, lionBitmap, wxPoint(209, 32), wxSize(100, 100));
    new wxStaticBitmap(panel, wxID_ANY, tigerBitmap, wxPoint(406, 32), wxSize(100, 100));
    new wxStaticBitmap(panel, wxID_ANY, bearBitmap, wxPoint(603, 32), wxSize(100, 100));
}

void Frame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("zookeeper\nversion 0.0.1 \n\nby Mark Edmunds\n\n CIT 66 \nSpring 2025\n\n",
                 "About zookeeper", wxOK | wxICON_INFORMATION);
}

void Frame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("I built this GUI using wxWidgets");
}


void Frame::generateReport(wxCommandEvent& event) {
    wxMessageBox("Generate a report of all animals in the zoo", "Generate Report", wxOK | wxICON_INFORMATION);
    // Call the generateReport function in ZooManager
    std::cout << "Hello world from generateReport!\n";
    zoo.generateReport();
    // read from the ../zooReport.txt file and display it in the list box
    std::ifstream file("../data/zooReport.txt");
    std::string line;
    while (std::getline(file, line)) {
        // Append each line to the list box
        report_box->Append(line);
    }
}

void Frame::processAnimals(wxCommandEvent& event) {
    wxMessageBox("Process the incoming animals", "Process Animals", wxOK  | wxICON_INFORMATION);
    // Call the processAnimals function in ZooManager
    std::cout << "Hello world from processAnimals!\n";
    std::string filename = "../data/arrivingAnimals.txt";
    std::vector<std::vector<std::string>> data = parseFile(filename);
    for (int i = 0; i < data.size(); i++) {
        std::string age = splitString(data[i][0], ' ', 0);
        std::string weight = splitString(data[i][3], ' ', 1);
        std::string species = splitString(data[i][0], ' ', 4);
        std::string birthSeason = splitString(data[i][1], ' ', 3);
        std::string origin = splitString(data[i][5], ' ', 1);
        std::string color = data[i][2];
        std::cout << origin << "\n";
        std::cout << birthSeason << "\n";
        std::cout << color << "\n";
        color.erase(0, color.find_first_not_of(' '));
        if (species == "hyena") {
            std::cout << "Hyena\n";
            std::string hyenaName = animal::Hyena::generateName();
           while (zoo.usedAnimalNames.contains(hyenaName)) {
               hyenaName = animal::Hyena::generateName();
           }
            zoo.usedAnimalNames.insert(hyenaName);
            animal::Hyena hyena("Hy", hyenaName, std::stoi(age), std::stoi(weight), species, origin, birthSeason, color);
            std::cout << "Hyena: " << hyenaName << "\n";
            zoo.genBirthDate(hyena.getBirthSeason(), hyena.getAge());
            zoo.processAnimals(hyena);
        } else if (species == "bear") {
            std::cout << "Bear\n";
            std::string bearName = animal::Bear::generateName();
            while (zoo.usedAnimalNames.contains(bearName)) {
                bearName = animal::Bear::generateName();
            }
            zoo.usedAnimalNames.insert(bearName);
            animal::Bear bear("Be", bearName, std::stoi(age), std::stoi(weight), species, origin, birthSeason, color);
            zoo.genBirthDate(bear.getBirthSeason(), bear.getAge());
            zoo.processAnimals(bear);
        } else if (species == "lion") {
            std::cout << "Lion\n";
            std::string lionName = animal::Lion::generateName();
            while (zoo.usedAnimalNames.contains(lionName)) {
                lionName = animal::Lion::generateName();
            }
            zoo.usedAnimalNames.insert(lionName);
            animal::Lion lion("Li", lionName, std::stoi(age), std::stoi(weight), species, origin, birthSeason, color);
            zoo.processAnimals(lion);
        } else if (species == "tiger") {
            std::cout << "Tiger\n";
            std::string tigerName = animal::Tiger::generateName();
            while (zoo.usedAnimalNames.contains(tigerName)) {
                tigerName = animal::Tiger::generateName();
            }
            zoo.usedAnimalNames.insert(tigerName);
            animal::Tiger tiger("Ti", tigerName, std::stoi(age), std::stoi(weight), species, origin, birthSeason, color);
            zoo.genBirthDate(tiger.getBirthSeason(), tiger.getAge());
            zoo.processAnimals(tiger);
        } else {
            std::cerr << "Unknown species: " << species << std::endl;
        }
        if (lion_count_label) {
            lion_count_label->SetLabel(std::to_string(zoo.countAnimals()["Lion"]));
        }
        if (hyena_count_label) {
            hyena_count_label->SetLabel(std::to_string(zoo.countAnimals()["Hyena"]));
        }
        if (tiger_count_label) {
            tiger_count_label->SetLabel(std::to_string(zoo.countAnimals()["Tiger"]));
        }
        if (bear_count_label) {
            bear_count_label->SetLabel(std::to_string(zoo.countAnimals()["Bear"]));
        }
        SetStatusText("Processed " + std::to_string(i + 1) + " animals");
    }
    for (const auto &hyena : zoo.hyenaEnclosure) {
        hyena_list_box->Append(hyena.getID() +"; " + hyena.getName() + "; " + std::to_string(hyena.getAge()));
    }
    for (const auto &lion : zoo.lionEnclosure) {
        lion_list_box->Append(lion.getID() + "; " + lion.getName() + "; " + std::to_string(lion.getAge()));
    }
    for (const auto &tiger : zoo.tigerEnclosure) {
        tiger_list_box->Append(tiger.getID() + "; " + tiger.getName() + "; " + std::to_string(tiger.getAge()));
    }
    for (const auto &bear : zoo.bearEnclosure) {
        bear_list_box->Append(bear.getID() + "; " + bear.getName() + "; " + std::to_string(bear.getAge()));
    }
}

void Frame::onOpenFile(wxCommandEvent &event) {
    wxFileDialog openFileDialog(
            this,
            "Open file",
            "", "",
            "Text files (*.txt)|*.txt|All files (*.*)|*.*",
            wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK)
    {
        wxString path = openFileDialog.GetPath();
        wxMessageBox("You selected: " + path, "File Selected");
    }
}
