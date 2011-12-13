// ======================================================================================
// File         : test_alternative.cc
// Author       : Gao Lei 
// Last Change  : 12/05/2011 | 02:15:42 AM | Monday,December
// Description  : 
// ======================================================================================

#include <string>
#include <iostream>
#include "../all.h"
#include "../src/action/action.h"



int main()
{

    std::string str;
    typedef std::string::iterator Iterator;
    auto p1 = _literal<Iterator>("FTP") <= to_string<Iterator>(str);
    auto p2 = _literal<Iterator>("HTTP") <= to_string<Iterator>(str);
    auto p3 = _literal<Iterator>("TCP") <= to_string<Iterator>(str);
    auto p = _alternative<Iterator>( p1,
                                     p2,
                                     p3,
                                     _literal<Iterator>("IP") <= to_string<Iterator>(str)
                                   );
    {

        std::string str = "HTTP";
        std::string::iterator it = str.begin();
        if(p(it,str.end()) )
        {
            std::cout<<str<<std::endl;
        }

    }
    {
        std::string str = "TCP";
        std::string::iterator it = str.begin();
        if(p(it,str.end()) )
        {
            std::cout<<str<<std::endl;
        }

    }
    {
        std::string str = "IP";
        std::string::iterator it = str.begin();
        if(p(it,str.end()) )
        {
            std::cout<<str<<std::endl;
        }

    }
    ////////////////////////////////////////////////////////


}


