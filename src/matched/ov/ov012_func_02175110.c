/*
 * function: COLOSSEUM_FlushChoiceReplies
 * address: 0x02175110
 * packet: pkt_ov012_02175110
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   COLOSSEUM_SendChoiceReply 0x02174D2C thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203D378(void);
extern int COLOSSEUM_SendChoiceReply(char *a, u32 b, u32 c);
void COLOSSEUM_FlushChoiceReplies(u8 *p)
{
    int i;
    if (func_0203D378()) {
        for (i=0;i<4;i++) {
            if ((p+i)[0xd0] != 255 && COLOSSEUM_SendChoiceReply((char *)p,i,(p+i)[0xd0]) == 1)
                (p+i)[0xd0] = 255;
        }
    }
}
