/*
 * function: func_02186958
 * address: 0x02186958
 * packet: pkt_ov023_02186958
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02186938 0x02186938 thumb ov023
 */
typedef unsigned char u8;
typedef struct { u8 b[4]; u8 lo:3; u8 mid:3; u8 hi:2; u8 b5; } Rec;
extern void func_02186938(Rec *);
void func_02186958(char *p)
{
    if (*(int *)(p + 0xBB8) != *(int *)(p + 0xBBC)) {
        func_02186938((Rec *)(p + *(int *)(p + 0xBB8) * 30));
        *(int *)(p + 0xBB8) += 1;
        if (*(int *)(p + 0xBB8) >= 100) *(int *)(p + 0xBB8) = 0;
    }
}
