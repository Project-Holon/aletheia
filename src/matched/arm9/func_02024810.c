/*
 * function: PMS_WORD_GetString
 * address:  0x02024810
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 */

extern int PMS_WORD_SplitWordId(unsigned int v, unsigned int *a1, unsigned int *a2);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
void PMS_WORD_GetString(char *p, int a1, int a2)
{
    int x, y;
    PMS_WORD_SplitWordId(a1, (unsigned int *)(&x), (unsigned int *)(&y));
    MSGDATA_ReadString((struct MsgBank *)(*(int *)(p + 4 + x * 4)), y, (void *)a2);
}
