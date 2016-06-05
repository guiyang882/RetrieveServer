//
// Created by 贵阳 on 6/3/16.
//

#ifndef RETRIEVESERVER_RETRIEVESERVER_H
#define RETRIEVESERVER_RETRIEVESERVER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <Ice/Ice.h>

#include "rpc/retrieve/ImageRetrieveRpc.h"
#include "utils/log.h"
#include "threadpool/threadpool.h"
#include "algorithm/retrieve/utils/retrieveutils.h"
#include "algorithm/retrieve/utils/pgdb.h"

using namespace std;
using namespace RPCImgRecong;
using namespace Ice;

class RetrieveServer : public ImgRetrieval {
public:
    RetrieveServer();
    ~RetrieveServer();

public:
    void log_InputParameters(const DictStr2Str& mapArg);
    void log_OutputResult(const WordWiki& wiki);
    void log_OutputResult(const WordRes& wordres);
    void log_OutputResult(const ImgRes& imgres);

public:
    virtual WordWiki wordGetKnowledge(const string& word, const Ice::Current&);
    virtual WordRes wordSearch(const DictStr2Str& mapArg, const Ice::Current&);
    virtual ImgRes wordSearchImg(const DictStr2Str& mapArg, const Ice::Current&);
    virtual int imgSearchAsync(const DictStr2Str& mapArg, const Ice::Current&);
    virtual ImgRes fetchImgSearchResult(const DictStr2Str& mapArg, const Ice::Current&);
    virtual ImgRes imgSearchSync(const DictStr2Str& mapArg, const Ice::Current&);

private:
    ThreadPool* p_threadPool;
};


#endif //RETRIEVESERVER_RETRIEVESERVER_H
