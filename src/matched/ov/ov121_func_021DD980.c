/*
 * function: func_021DD980
 * address: 0x021DD980
 * packet: pkt_ov121_021DD980
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DA3C0 0x021DA3C0 thumb ov121
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 */
typedef unsigned char  u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_020307B0(void *);
extern void func_021DA3C0(u8 *p);
extern void func_021DBEE4(void *);
void func_021DD980(char *p)
{
    if (*(void **)(p+0x128)) {
        func_02030EAC(*(void **)(p+0x128));
        *(void **)(p+0x128)=0;
    }
    if (*(void **)(p+0x13c)) func_020307B0(*(void **)(p+0x13c));
    if (*(void **)(p+0x134)) func_020307B0(*(void **)(p+0x134));
    func_021DA3C0(*(void **)(p+0x144));
    func_021DBEE4(p);
    func_020307B0(p);
}
