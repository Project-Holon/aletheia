/*
 * file:     unit_0215FDA4_p18.c
 * unit:     yes
 * function: func_02162E5C, func_02162E94
 * address:  0x02162E5C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CPSiFree  0x021A82B0  data
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   id_string        0x020050F0  data
 *   OSi_ThreadInfo   0x02150FEC  data
 */
struct _CPSSoc;
struct _CPSSslConnection {
    char pad0[0x455];
    unsigned char f455;
    char pad1[0x824 - 0x455 - 1];
    void *f824;
};

struct _CPSSoc {
    char pad0[0xc];
    struct _CPSSslConnection *con;
};

typedef unsigned short u16;

typedef struct OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

extern void OSi_ReferSymbol(const char *symbol);
void CPSi_SslClose(struct _CPSSoc *soc);
void CPS_SetSsl(int mode);
extern OSThreadInfo OSi_ThreadInfo;
extern char id_string[];


extern void (*CPSiFree)(void *ptr);


void CPSi_SslClose(struct _CPSSoc *soc)
{
    struct _CPSSslConnection *con = soc->con;
    void *p;

    con->f455 = 0;
    p = con->f824;
    if (p != 0)
        CPSiFree(p);
    con->f824 = 0;
}


void CPS_SetSsl(int mode)
{
    struct _CPSSoc *soc;

    OSi_ReferSymbol(id_string);
    soc = *(struct _CPSSoc **)((char *)OSi_ThreadInfo.current + 0xa4);
    if (soc != 0)
        *(unsigned char *)((char *)soc + 9) = mode;
}
