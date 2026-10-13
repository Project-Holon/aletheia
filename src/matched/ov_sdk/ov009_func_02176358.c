/*
 * function: DWCi_NodeInfoList_GetServerNodeInfo
 * address:  0x02176358
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Null when the word at +0x50 is below 1, else the module pointer plus 0x54.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void *DWCi_NodeInfoList_GetServerNodeInfo(void)
{
    int func_02175F3C(void);
    void *p = (void *)func_02175F3C();
    if (*(int *)((char *)p + 0x50) < 1) return 0;
    return (char *)func_02175F3C() + 0x54;
}
