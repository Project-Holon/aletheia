/*
 * function: CPS_SetSsl
 * address:  0x02162E94
 * packet:   pkt_ov009_02162E94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SetSsl (ssl.o)
 *
 * symbols:
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   id_string        0x020050F0  data
 *   OSi_ThreadInfo   0x02150FEC  data
*/

typedef unsigned short u16;

typedef struct OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

struct _CPSSoc;

extern OSThreadInfo OSi_ThreadInfo;
extern char id_string[];
extern void OSi_ReferSymbol(const char *symbol);

void CPS_SetSsl(int mode)
{
    struct _CPSSoc *soc;

    OSi_ReferSymbol(id_string);
    soc = *(struct _CPSSoc **)((char *)OSi_ThreadInfo.current + 0xa4);
    if (soc != 0)
        *(unsigned char *)((char *)soc + 9) = mode;
}
