/*
 * function: func_021D504C
 * address: 0x021D504C
 * packet: pkt_ov123_021D504C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020414EC 0x020414EC arm
 *   func_021D4FAC 0x021D4FAC thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4EF0 0x021D4EF0 thumb ov123
 *   func_021D4384 0x021D4384 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4AFC 0x021D4AFC thumb ov123
 *   func_021D5020 0x021D5020 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Big;
struct MsgBank;
struct Sub020071E4Ctrl;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_020414EC(u32 i);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D4FAC(char *);
extern void func_021D4244(char *,void *,int);
extern void func_021D4EF0(char *,int,int);
extern void func_021D4384(char *);
extern void func_021D4D40(char *,int);
extern void func_021D4AFC(char *);
extern void func_021D5020(char *);
extern void func_021D4A04(char *);
void func_021D504C(char *p)
{
    if (func_020279E8(*(void **)(p+0x238))) {
        if (!func_02027A04(*(void **)(p+0x238))) {
            if (func_020071F0(func_02012EBC(*(void **)(p+0x260)))) {
                func_02045CAC(*(void **)(p+0x24),46,*(void **)(p+0x38));
                func_021D4FAC(p);
                func_021D4244(p,func_021D4AFC,0x50d);
            } else {
                func_02045CAC(*(void **)(p+0x24),6,*(void **)(p+0x38));
                func_021D4EF0(p,4,0);
                func_021D4384(p);
                func_021D4244(p,func_021D5020,0x519);
            }
        } else {
            func_020414EC(5);
            *(int *)(p+8)=0;
            func_021D4244(p,func_021D4A04,0x51f);
            func_021D4D40(p,0);
        }
        func_02027858(*(void **)(p+0x238));
        *(void **)(p+0x238)=0;
    }
}
