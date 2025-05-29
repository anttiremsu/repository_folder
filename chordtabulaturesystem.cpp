// created by Antti Remsu and Mitri Maarajärvi 
// Chord Tabulature System 

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

int amountOfChords = 2; // this is increased if more chord types are added
int lowE, A, D, G, B, highE, offset = 0, debug; // the strings are named based on standard tuning for clarity
int acci, chord, tune, loop; // the parameters of chord
int tune1 = 0, tune2 = 0, tune3 = 0, tune4 = 0, tune5 = 0, tune6 = 0; // tuning system declared and initialized
string string1, string2, string3, string4, string5, string6; 
char note, more;
// tuning
class Tune {
protected:
    vector<pair<string, int>> tuning;

public:
    Tune(vector<pair<string, int>> notes) : tuning(notes) {}

    // user dialog output
    string printTuning(string selectedTune) {
        cout << selectedTune << " tuning selected:\n";
        for (const auto& note : tuning) {
            cout << note.first << "|-\n";
        }
        cout << endl;
        return (selectedTune);
    }

    // tuning system internal structure
    void tuneGuitar() {
        tune1 = tuning[0].second;
        tune2 = tuning[1].second;
        tune3 = tuning[2].second;
        tune4 = tuning[3].second;
        tune5 = tuning[4].second;
        tune6 = tuning[5].second;

        string1 = tuning[0].first;
        string2 = tuning[1].first;
        string3 = tuning[2].first;
        string4 = tuning[3].first;
        string5 = tuning[4].first;
        string6 = tuning[5].first;
    }
};

// preset tuning systems
class eStandard : public Tune {
public:
    eStandard() : Tune({
        {"e", 0}, {"B", 0}, {"G", 0}, {"D", 0}, {"A", 0}, {"E", 0}
    }) {}
};

class halfStep : public Tune {
public:
    halfStep() : Tune({
        {"d#", 1}, {"A#", 1}, {"F#", 1}, {"C#", 1}, {"G#", 1}, {"D#", 1}
    }) {}
};

class DropC : public Tune {
public:
    DropC() : Tune({
        {"d", 2}, {"A", 2}, {"F", 2}, {"C", 2}, {"G", 2}, {"C", 4}
    }) {}
};
// storage for final print of session
class ChordStorage {
private:
    vector<tuple<char, int, int>> learnedChords;

public:
    void addChord(char note, int acci, int chordType) {
        learnedChords.emplace_back(note, acci, chordType);
    }

    const vector<tuple<char, int, int>>& getChords() const {
        return learnedChords;
    }

    void clear() {
        learnedChords.clear();
    }
};

ChordStorage storage;

void clearOffset() {
    offset = 0;
}

void check() {
    if (note == 'A' || note == 'B' || note == 'H' || note == 'C' ||
        note == 'D' || note == 'E' || note == 'F' || note == 'G') {
        cout << "Note " << note << " selected\n" << endl;
    }
    else {
        debug = 1;
        more = 'Y';
        cout << "Invalid input. Please use the given alphabets." << endl;
    }
}

// all of the base types for CAGED chords
void chordBaseC(string chordTypeStr) {
    highE = 0 + tune1;
    B = 1 + tune2;
    G = 0 + tune3;
    D = 2 + tune4;
    A = 3 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 9}, {'B', 10}, {'C', 0}, {'D', 2}, {'E', 4}, {'F', 5}, {'G', 7}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (chord == 2) {}
    else if (chord == 3) { D--; }

    if (offset < 0) { offset = offset + 12; }

    cout << "-------------------" << endl;
    cout << "|" << string1 << "|-x" << "-" << endl;
    cout << "|" << string2 << "|-" << B + offset << "-" << endl;
    cout << "|" << string3 << "|-" << G + offset << "-" << endl;
    cout << "|" << string4 << "|-" << D + offset << "-" << endl;
    cout << "|" << string5 << "|-" << A + offset << "-" << endl;
    cout << "|" << string6 << "|-x" << "-\n" << endl;
    cout << "*******************" << endl;

    storage.addChord(note, acci, chord);
    clearOffset();
}

void chordBaseA(string chordTypeStr) {
    highE = 0 + tune1;
    B = 2 + tune2;
    G = 2 + tune3;
    D = 2 + tune4;
    A = 0 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 0}, {'B', 2}, {'C', 3}, {'D', 5}, {'E', 7}, {'F', 8}, {'G', 10}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (chord == 2) {}
    else if (chord == 3) { B--; }

    if (offset < 0) { offset = offset + 12; }

    cout << "-------------------" << endl;
    cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
    cout << "|" << string2 << "|-" << B + offset << "-" << endl;
    cout << "|" << string3 << "|-" << G + offset << "-" << endl;
    cout << "|" << string4 << "|-" << D + offset << "-" << endl;
    cout << "|" << string5 << "|-" << A + offset << "-" << endl;
    cout << "|" << string6 << "|-x" << "-\n" << endl;
    cout << "*******************" << endl;

    storage.addChord(note, acci, chord);
    clearOffset();
}

void chordBaseG(string chordTypeStr) {
    highE = 3 + tune1;
    B = 0 + tune2;
    G = 0 + tune3;
    D = 0 + tune4;
    A = 2 + tune5;
    lowE = 3 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 2}, {'B', 4}, {'C', 5}, {'D', 7}, {'E', 9}, {'F', 10}, {'G', 0}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (chord == 2) {}
    else if (chord == 3) { A--; }

    if (offset < 0) { offset = offset + 12; }

    cout << "-------------------" << endl;
    cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
    cout << "|" << string2 << "|-" << B + offset << "-" << endl;
    cout << "|" << string3 << "|-" << G + offset << "-" << endl;
    cout << "|" << string4 << "|-" << D + offset << "-" << endl;
    cout << "|" << string5 << "|-" << A + offset << "-" << endl;
    cout << "|" << string6 << "|-" << lowE + offset << "-\n" << endl;
    cout << "*******************" << endl;

    storage.addChord(note, acci, chord);
    clearOffset();
}

void chordBaseE(string chordTypeStr) {
    highE = 0 + tune1;
    B = 0 + tune2;
    G = 1 + tune3;
    D = 2 + tune4;
    A = 2 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 5}, {'B', 7}, {'C', 8}, {'D', 10}, {'E', 0}, {'F', 1}, {'G', 3}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (chord == 2) {}
    else if (chord == 3) { G--; }

    if (offset < 0) { offset = offset + 12; }

    cout << "-------------------" << endl;
    cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
    cout << "|" << string2 << "|-" << B + offset << "-" << endl;
    cout << "|" << string3 << "|-" << G + offset << "-" << endl;
    cout << "|" << string4 << "|-" << D + offset << "-" << endl;
    cout << "|" << string5 << "|-" << A + offset << "-" << endl;
    cout << "|" << string6 << "|-" << lowE + offset << "-\n" << endl;
    cout << "*******************" << endl;

    storage.addChord(note, acci, chord);
    clearOffset();
}

void chordBaseD(string chordTypeStr) {
    highE = 3 + tune1;
    B = 4 + tune2;
    G = 3 + tune3;
    D = 0 + tune4;

    unordered_map<char, int> noteValues = {
        {'A', 7}, {'B', 9}, {'C', 10}, {'D', 0}, {'E', 2}, {'F', 3}, {'G', 5}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (chord == 2) {}
    else if (chord == 3) { highE--; }

    if (offset < 0) { offset = offset + 12; }

    cout << "-------------------" << endl;
    cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
    cout << "|" << string2 << "|-" << B + offset << "-" << endl;
    cout << "|" << string3 << "|-" << G + offset << "-" << endl;
    cout << "|" << string4 << "|-" << D + offset << "-" << endl;
    cout << "|" << string5 << "|-x" << "-" << endl;
    cout << "|" << string6 << "|-x" << "-\n" << endl;
    cout << "*******************" << endl;

    storage.addChord(note, acci, chord);
    clearOffset();
}

void chordBaseC() {
    highE = 0 + tune1;
    B = 1 + tune2;
    G = 0 + tune3;
    D = 2 + tune4;
    A = 3 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 9}, {'B', 10}, {'C', 0}, {'D', 2}, {'E', 4}, {'F', 5}, {'G', 7}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (offset < 0) { offset = offset + 12; }

    for (int i = 0; i < amountOfChords; i++) {
        string currentChordType = (i == 0) ? "major" : "minor";
        if (i == 0) { chord = 2; }
        else if (i == 1) { chord = 3; D--; }

        cout << "\n*******************" << endl;
        cout << note << (acci == 2 ? "#" : (acci == 3 ? "b" : "")) << " " << currentChordType << ":\n" << endl;
        cout << "*******************" << endl;
        cout << "|" << string1 << "|-x" << "-" << endl;
        cout << "|" << string2 << "|-" << B + offset << "-" << endl;
        cout << "|" << string3 << "|-" << G + offset << "-" << endl;
        cout << "|" << string4 << "|-" << D + offset << "-" << endl;
        cout << "|" << string5 << "|-" << A + offset << "-" << endl;
        cout << "|" << string6 << "|-x" << "-\n" << endl;
        cout << "*******************" << endl;

        storage.addChord(note, acci, chord);
    }

    clearOffset();
}

void chordBaseA() {
    highE = 0 + tune1;
    B = 2 + tune2;
    G = 2 + tune3;
    D = 2 + tune4;
    A = 0 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 0}, {'B', 2}, {'C', 3}, {'D', 5}, {'E', 7}, {'F', 8}, {'G', 10}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (offset < 0) { offset = offset + 12; }

    for (int i = 0; i < amountOfChords; i++) {
        string currentChordType = (i == 0) ? "major" : "minor";
        if (i == 0) { chord = 2; }
        else if (i == 1) { chord = 3; B--; }
        cout << "\n*******************" << endl;
        cout << note << (acci == 2 ? "#" : (acci == 3 ? "b" : "")) << " " << currentChordType << ":\n" << endl;
        cout << "*******************" << endl;
        cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
        cout << "|" << string2 << "|-" << B + offset << "-" << endl;
        cout << "|" << string3 << "|-" << G + offset << "-" << endl;
        cout << "|" << string4 << "|-" << D + offset << "-" << endl;
        cout << "|" << string5 << "|-" << A + offset << "-" << endl;
        cout << "|" << string6 << "|-x" << "-\n" << endl;
        cout << "*******************" << endl;

        storage.addChord(note, acci, chord);
    }
    clearOffset();
}

void chordBaseG() {
    highE = 3 + tune1;
    B = 0 + tune2;
    G = 0 + tune3;
    D = 0 + tune4;
    A = 2 + tune5;
    lowE = 3 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 2}, {'B', 4}, {'C', 5}, {'D', 7}, {'E', 9}, {'F', 10}, {'G', 0}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (offset < 0) { offset = offset + 12; }

    for (int i = 0; i < amountOfChords; i++) {
        string currentChordType = (i == 0) ? "major" : "minor";
        if (i == 0) { chord = 2; }
        else if (i == 1) { chord = 3; A--; }
        cout << "\n*******************" << endl;
        cout << note << (acci == 2 ? "#" : (acci == 3 ? "b" : "")) << " " << currentChordType << ":\n" << endl;
        cout << "*******************" << endl;
        cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
        cout << "|" << string2 << "|-" << B + offset << "-" << endl;
        cout << "|" << string3 << "|-" << G + offset << "-" << endl;
        cout << "|" << string4 << "|-" << D + offset << "-" << endl;
        cout << "|" << string5 << "|-" << A + offset << "-" << endl;
        cout << "|" << string6 << "|-" << lowE + offset << "-\n" << endl;
        cout << "*******************" << endl;

        storage.addChord(note, acci, chord);
    }

    clearOffset();
}

void chordBaseE() {
    highE = 0 + tune1;
    B = 0 + tune2;
    G = 1 + tune3;
    D = 2 + tune4;
    A = 2 + tune5;
    lowE = 0 + tune6;

    unordered_map<char, int> noteValues = {
        {'A', 5}, {'B', 7}, {'C', 8}, {'D', 10}, {'E', 0}, {'F', 1}, {'G', 3}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (offset < 0) { offset = offset + 12; }

    for (int i = 0; i < amountOfChords; i++) {
        string currentChordType = (i == 0) ? "major" : "minor";
        if (i == 0) { chord = 2; }
        else if (i == 1) { chord = 3; G--; }

        cout << "\n*******************" << endl;
        cout << note << (acci == 2 ? "#" : (acci == 3 ? "b" : "")) << " " << currentChordType << ":\n" << endl;
        cout << "*******************" << endl;
        cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
        cout << "|" << string2 << "|-" << B + offset << "-" << endl;
        cout << "|" << string3 << "|-" << G + offset << "-" << endl;
        cout << "|" << string4 << "|-" << D + offset << "-" << endl;
        cout << "|" << string5 << "|-" << A + offset << "-" << endl;
        cout << "|" << string6 << "|-" << lowE + offset << "-\n" << endl;
        cout << "*******************" << endl;

        storage.addChord(note, acci, chord);
    }

    clearOffset();
}

void chordBaseD() {
    highE = 3 + tune1;
    B = 4 + tune2;
    G = 3 + tune3;
    D = 0 + tune4;

    unordered_map<char, int> noteValues = {
        {'A', 7}, {'B', 9}, {'C', 10}, {'D', 0}, {'E', 2}, {'F', 3}, {'G', 5}
    };

    offset += noteValues[note];

    if (acci == 1) {}
    else if (acci == 2) { offset++; }
    else if (acci == 3) { offset--; }

    if (offset < 0) { offset = offset + 12; }

    for (int i = 0; i < amountOfChords; i++) {
        string currentChordType = (i == 0) ? "major" : "minor";
        if (i == 0) { chord = 2; }
        else if (i == 1) { chord = 3; highE--; }
        cout << "\n*******************" << endl;
        cout << note << (acci == 2 ? "#" : (acci == 3 ? "b" : "")) << " " << currentChordType << ":\n" << endl;
        cout << "*******************" << endl;
        cout << "|" << string1 << "|-" << highE + offset << "-" << endl;
        cout << "|" << string2 << "|-" << B + offset << "-" << endl;
        cout << "|" << string3 << "|-" << G + offset << "-" << endl;
        cout << "|" << string4 << "|-" << D + offset << "-" << endl;
        cout << "|" << string5 << "|-x" << "-" << endl;
        cout << "|" << string6 << "|-x" << "-\n" << endl;
        cout << "*******************" << endl;

        storage.addChord(note, acci, chord);
    }

    clearOffset();
}

void clear() {
    loop = 0;
    debug = 0;
}

int main()
{
    note = 0;
    debug = 0;
    more = 'Y';

    int tuneInput;
    // prompt user for tuning system
    cout << "Select your tuning" << endl;
    cout << "[1] E standard" << endl;
    cout << "[2] Half step down" << endl;
    cout << "[3] Drop C" << endl;
    cin >> tuneInput;
    cout << endl;

    // select tuning based on user input
    if (tuneInput == 1) {
        eStandard Etuning;
        Etuning.printTuning("E standard");
        Etuning.tuneGuitar();
    }
    else if (tuneInput == 2) {
        halfStep halfStepTuning;
        halfStepTuning.printTuning("Half step down (D# standard)");
        halfStepTuning.tuneGuitar();
    }
    else if (tuneInput == 3) {
        DropC dropCtuning;
        dropCtuning.printTuning("Drop C");
        dropCtuning.tuneGuitar();
    }

    do {
        clear();
        string accidentalStr = "";
        string chordTypeStr = "major";
        // prompt user for root of chord
        cout << "Choose a note:" << endl;
        cout << "[A] [B/H] [C] [D] [E] [F] [G]" << endl;
        cin >> note;

        if (islower(note)) { note = toupper(note); }

        check();
        if (debug == 1) { continue; }
        // prompt user for accidentals
        cout << "Natural, sharp or flat?" << endl;
        cout << "[1] " << note << endl;
        cout << "[2] " << note << "#" << endl;
        cout << "[3] " << note << "b" << endl;
        cin >> acci;

        if (cin.fail() || acci >= 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please use the given numbers.\n" << endl;
            continue;
        }

        if (acci == 2) accidentalStr = "#";
        else if (acci == 3) accidentalStr = "b";
        // prompt user for chord type
        cout << note << accidentalStr << " selected" << endl;
        cout << "\n[1] One of each [2] Major or [3] Minor?" << endl;
        cin >> chord;

        if (cin.fail() || chord > amountOfChords + 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please use the given numbers.\n" << endl;
            continue;
        }
        // here the user input is evaluated and output created based on given parameters
        if (chord == 3) chordTypeStr = "minor";

        if (chord == 1) {
            if (note == 'C') { chordBaseC(); }
            else if (note == 'D') { chordBaseD(); }
            else if (note == 'E' || note == 'F') { chordBaseE(); }
            else if (note == 'G') { chordBaseG(); }
            else if (note == 'A' || note == 'B') { chordBaseA(); }
        }
        else if (note == 'E' || note == 'F') {
            cout << "\n*******************" << endl;
            cout << note << accidentalStr << " " << chordTypeStr << ":\n" << endl;
            cout << "*******************" << endl;
            chordBaseE(chordTypeStr);
            chordBaseA(chordTypeStr);
            chordBaseC(chordTypeStr);
            chordBaseD(chordTypeStr);
            chordBaseG(chordTypeStr);
        }
        else if (note == 'A' || note == 'B' || note == 'H') {
            cout << "\n*******************" << endl;
            cout << note << accidentalStr << " " << chordTypeStr << ":\n" << endl;
            cout << "*******************" << endl;
            chordBaseA(chordTypeStr);
            chordBaseE(chordTypeStr);
            chordBaseC(chordTypeStr);
            chordBaseD(chordTypeStr);
            chordBaseG(chordTypeStr);
        }
        else  if (note == 'C') {
            cout << "\n*******************" << endl;
            cout << note << accidentalStr << " " << chordTypeStr << ":\n" << endl;
            cout << "*******************" << endl;
            chordBaseC(chordTypeStr);
            chordBaseA(chordTypeStr);
            chordBaseE(chordTypeStr);
            chordBaseD(chordTypeStr);
            chordBaseG(chordTypeStr);
        }
        else if (note == 'G') {
            cout << "\n*******************" << endl;
            cout << note << accidentalStr << " " << chordTypeStr << ":\n" << endl;
            cout << "*******************" << endl;
            chordBaseG(chordTypeStr);
            chordBaseE(chordTypeStr);
            chordBaseA(chordTypeStr);
            chordBaseC(chordTypeStr);
            chordBaseD(chordTypeStr);
        }
        else if (note == 'D') {
            cout << "\n*******************" << endl;
            cout << note << accidentalStr << " " << chordTypeStr << ":\n" << endl;
            cout << "*******************" << endl;
            chordBaseD(chordTypeStr);
            chordBaseA(chordTypeStr);
            chordBaseE(chordTypeStr);
            chordBaseC(chordTypeStr);
            chordBaseG(chordTypeStr);
        }
        // print is done, ask for more or exit
        cout << "Would you like to learn another chord? [Y] [N]" << endl;
        cin >> more;
    } while (more == 'Y' || more == 'y');
    // and the final function of printing all chords used during session utilizing storage
    cout << "Show all learned chords? [Y/N]\n";
    cin >> more;

    if (more == 'Y' || more == 'y') {
        for (const auto& storedChord : storage.getChords()) {
            char n = get<0>(storedChord);
            int a = get<1>(storedChord);
            int c = get<2>(storedChord);
            string chordType = (c == 3) ? "minor" : "major";
            string acciStr = (a == 2) ? "#" : (a == 3) ? "b" : "";

            cout << "Stored Chord: " << n << acciStr << " " << chordType << endl;

            if (n == 'E' || n == 'F') {
                chordBaseE(chordType);
            }
            else if (n == 'A' || n == 'B' || n == 'H') {
                chordBaseA(chordType);
            }
            else  if (n == 'C') {
                chordBaseC(chordType);
            }
            else if (n == 'G') {
                chordBaseG(chordType);
            }
            else if (n == 'D') {
                chordBaseD(chordType);
            }
        }
    }
    return 0;
}