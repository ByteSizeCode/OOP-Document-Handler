//
//  Methods.h
//
//  Created by Isaac Raval on 4/25/19.
//  Copyright © 2019 Isaac Raval. All rights reserved.
//

#ifndef Methods_h
#define Methods_h

#include <sstream>
#include <fstream>

void viewDocument() {
    string userWantingToQuitStatus = "";
    while(userWantingToQuitStatus != "QUIT") {
        //If no docs saved, return
        const int EMPTY = 0;
        if(docManager.allDocs().size() == EMPTY) {
            cout << "No saved documents. Cannot edit." << endl;
            return;
        }
    
        //Print all saved docs
        cout << "Currently saved docs:" << endl;
        for(int i = 0; i < docManager.allDocs().size(); i++) {
            cout << i << ": "
                << docManager.allDocs().at(i).getTitle()
                << endl;
        }
        cout << endl;
    
        //Ask user to select doc to view
        cout << "Enter document number to select:"
            << endl << ": ";
        int userInput = 0;
        cin >> userInput;
        
        //Ensure valid entry
        while(userInput > docManager.allDocs().size() - 1
              || userInput < 0) {
            cout << "Not a valid document. Please try again:" << endl << ": ";
            cin >> userInput;
        }
    
        //Print contents of selected document using document manager
        cout << "Viewing document " << userInput
            << ": " << endl
            << docManager.allDocs().at(userInput).getDocContents()
            << endl << endl;
        
        cout << "Type QUIT to quit or hit enter to view another document:" << endl;
        
        //Flush buffer
        cin.ignore();
        
        getline(cin, userWantingToQuitStatus);
    }
}

void newDocument() {
    //Set doc title
    string docTitle = "";
    cout << "Enter title for Document" << endl;
    getline(cin, docTitle);
    
    //Add content to doc
    cout << "Enter content. \"QUIT\" to quit:" << endl;
    string userInput = "";
    stringstream docContents;
    while(userInput != "QUIT") {
        getline(cin, userInput); //Get input line by line and check for QUIT
        if(userInput == "QUIT") {continue;} //Don't add QUIT to doc contents
        docContents << userInput; //Add input to document content
    }
    
    //Create doc object
    document myDoc;
    myDoc.setTitle(docTitle);
    myDoc.setDocContents(docContents.str());
    
    //Save document to DocumentManager
    docManager.addDocToManager(myDoc);
    
}
void removeDocument() {
    string userWantingToQuitStatus = "";
    while(userWantingToQuitStatus != "QUIT") {
        //If no docs saved, return
        const int EMPTY = 0;
        if(docManager.allDocs().size() == EMPTY) {
            cout << "No saved documents. Cannot remove." << endl;
            return;
        }
        
        //Print all saved docs
        cout << "Currently saved docs:" << endl;
        for(int i = 0; i < docManager.allDocs().size(); i++) {
            cout << i << ": "
            << docManager.allDocs().at(i).getTitle()
            << endl;
        }
        cout << endl;
        
        //Ask user to select doc to remove
        cout << "Enter number for document to remove:"
        << endl << ": ";
        int userInput = 0;
        cin >> userInput;
        
        //Ensure valid entry
        while(userInput > docManager.allDocs().size() - 1
              || userInput < 0) {
            cout << "Not a valid document. Please try again:" << endl << ": ";
            cin >> userInput;
        }
        
        //Delete selected document from document manager
        cout << "Removed document " << userInput << endl;
        docManager.removeDoc(userInput);
        
        cout << "Type QUIT to quit or hit enter to remove another document:" << endl;
        
        //Flush buffer
        cin.ignore();
        
        getline(cin, userWantingToQuitStatus);
    }
}

void homeMenu() {
    cout << "Home Menu:" << endl << "N-> new document, V-> view existing document, R-> remove existing document, Q-> quit:" << endl;
    string userAction = "";
    while(userAction != "N"
          && userAction != "V"
          && userAction != "R"
          && userAction != "Q") {
        getline(cin, userAction);
    }
    
    if(userAction == "N") {
        newDocument();
    }
    
    if(userAction == "V") {
        viewDocument();
    }
    
    if(userAction == "R") {
        removeDocument();
    }
    
    else if (userAction == "Q") {
        cout << "Please terminate the program manually as a safeguard."
            << " All data will be lost." << endl;
        return;
    }
}


#endif /* Methods_h */
