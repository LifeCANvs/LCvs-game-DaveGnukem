/*!
\file    djlang.cpp
\brief   Localization / languages
\author  David Joffe

Copyright (C) 2023 David Joffe
*/

#include "config.h"
#include "djlang.h"
#include <string>

std::string g_sCurLang="en";

//---------------------------------------------------------------------------

void djSelectLanguage(const char* szLang)
{
    if (szLang==nullptr|| szLang[0]==0)
    {
        g_sCurLang = "en";//default
    }
    else
    {
        g_sCurLang = szLang;
    }
    // Hm what's the longest possible language CODE (with region etc.) hrm?
    if (g_sCurLang.length()>32)// Trim if overly long
        g_sCurLang = g_sCurLang.substr(0, 32);
}

const char* djGetLanguage()
{
    return g_sCurLang.c_str();
}

bool djLang::DoTranslations()
{
    // Hrm, is this correct? Maybe default language should be 'none' and 'en' could host translations .. that way can do things like the pun
    return !g_sCurLang.empty() && g_sCurLang!="en";
}
//---------------------------------------------------------------------------