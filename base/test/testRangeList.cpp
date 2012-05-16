#include "RangeList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char *argv[])
{
    {
        RangeList rl;
        rl.addRange("chr1 ",100, 200);
        rl.addRange("chr10",20 , 30);
        rl.addRange("chr3 ",100, 300);
        rl.addRange("chr1 ",50 , 150);
        rl.addRange("chrX ",30 , 100);

        std::string range;
        for (unsigned int i = 0; i < rl.size(); i++) {
            rl.obtainRange(i, &range);
            printf("%s\n", range.c_str());
        }

        rl.sort();
        puts("\nAfter sorting:\n");
        for (unsigned int i = 0; i < rl.size(); i++) {
            rl.obtainRange(i, &range);
            printf("%s\n", range.c_str());
        }
    }
    {
        RangeList rl;
        rl.addRangeFile("testRangeList_input");
        for (RangeList::iterator iter = rl.begin();
             iter != rl.end();
             ++iter) {
            fprintf(stdout, "%s:%d-%d\n", iter.getChrom().c_str(), iter.getBegin(), iter.getEnd());
        };

        rl.sort();
        puts("\nAfter sorting:\n");

        for (RangeList::iterator iter = rl.begin();
             iter != rl.end();
             ++iter) {
            fprintf(stdout, "%s:%d-%d\n", iter.getChrom().c_str(), iter.getBegin(), iter.getEnd());
        };
    }
    return 0;
}
