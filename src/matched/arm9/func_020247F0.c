/*
 * function: PMS_WORD_Delete
 * address:  0x020247F0
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSGDATA_Delete  0x02045C04  arm
 */

struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PMS_WORD_Delete(char *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        MSGDATA_Delete((struct Rec *)(*(int *)(p + 4 + i * 4)));
    func_020307B0(p);
}
