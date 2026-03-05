#include "dbfntprint.h"

INCLUDE_ASM("asm/nonmatchings/DBG/dbfntprint", printline);

void _dbfntprint(char* buf) {
    char * cp;
    char * t;
    cp = buf, t = buf;

    while (*cp != 0) {
        switch (*cp) {
            case '\n':
                printline(cp, t);
                t = cp + 1;
                d.x = d.xofs;
                d.y += d.h;
            default:
                break;
            case '\t':
                d.x += d.w * printline(cp, t);
                t = cp + 1;
                d.x += d.w * d.tab;
                break;
            case '\r':
                printline(cp, t);
                t = cp + 1;
                d.x = d.xofs;
                break;
            case '\b':
                d.x += d.w * printline(cp, t);
                t = cp + 1;
                d.x -= d.w;
                break;
            }
        cp++;
    }
    printline(cp, t);
}

INCLUDE_ASM("asm/nonmatchings/DBG/dbfntprint", func_001DBD40);

INCLUDE_ASM("asm/nonmatchings/DBG/dbfntprint", func_001DBD60);

INCLUDE_ASM("asm/nonmatchings/DBG/dbfntprint", _dbfntvsnprintf);

INCLUDE_ASM("asm/nonmatchings/DBG/dbfntprint", func_001DBE30);
