//
//  Document.h
//
//  Created by Isaac Raval on 4/25/19.
//  Copyright © 2019 Isaac Raval. All rights reserved.
//

#ifndef Document_h
#define Document_h

#include <string>
using namespace std;

class document {
private:
    string title;
    string docContents;
public:
    void setDocContents(string contents) {
        docContents = contents;
    }
    void setTitle(string title) {
        this->title = title;
    }
    string getTitle() {
        return title;
    }
    string getDocContents() {
        return docContents;
    }
};

#endif /* Document_h */
