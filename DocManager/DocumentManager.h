//
//  DocumentManager.h
//
//  Created by Isaac Raval on 4/25/19.
//  Copyright © 2019 Isaac Raval. All rights reserved.
//

#ifndef DocumentManager_h
#define DocumentManager_h

class DocumentManager {
private:
    vector<document> listOfDocuments;
public:
    void addDocToManager (document myDocument) {
        listOfDocuments.push_back(myDocument);
    }
    void removeDoc(int i) {
        listOfDocuments.erase(listOfDocuments.begin() + i);
    }
    vector<document> allDocs() {
        return listOfDocuments;
    }
};

#endif /* DocumentManager_h */
