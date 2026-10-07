#ifndef ALETHEIA_G_DWCGLOBAL_H
#define ALETHEIA_G_DWCGLOBAL_H
/* g_021AA878 (arm9) */
struct DWCstDwcCnt;
struct DwcGlobal {
    int lastSocketError;
    struct DWCstDwcCnt *st;
};
#endif
