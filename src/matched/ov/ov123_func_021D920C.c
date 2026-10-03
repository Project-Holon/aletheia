/*
 * function: func_021D920C
 * address: 0x021D920C
 * packet: pkt_ov123_021D920C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D5644 0x021D5644 thumb ov123
 *   func_021D5E8C 0x021D5E8C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_0203CD98 0x0203CD98 arm
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 */
extern int func_020221A4(void *);
typedef unsigned char  u8;
struct S020315D4;
struct TaskMenu;
extern void func_02027858(struct TaskMenu *m);
extern void func_020307B0(void *);
extern void func_021D5644(char *p);
extern void func_021D5E8C(u8 *p);
extern void func_021D5B70(char *p);
extern int func_0203CD98(void);
extern void func_02156DE0(int,int);
extern void func_021B9838(u8 *p);
extern void func_02156DC4(int,int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int);
extern void func_02034A5C(int handle);
extern char ov114_id[];
int func_021D920C(void *a, int b, int c, char *p)
{
    if (!func_020221A4(a)) return 0;
    if (*(void **)(p+0x1c)) func_02027858(*(void **)(p+0x1c));
    if (*(void **)(p+0x38)) {
        func_020307B0(*(void **)(p+0x38));
        *(void **)(p+0x38)=0;
    }
    func_021D5644(*(void **)(p+0x18));
    func_021D5E8C(*(void **)(p+0x14));
    func_021D5B70(*(void **)(p+8));
    if (*(void **)(p+0x30)) func_020307B0(*(void **)(p+0x30));
    if (*(void **)(p+0x3c)) func_020307B0(*(void **)(p+0x3c));
    if (*(void **)(p+0x40)) func_020307B0(*(void **)(p+0x40));
    if (*(void **)(p+0xc)) func_020307B0(*(void **)(p+0xc));
    if (*(void **)(p+0x44)) func_020307B0(*(void **)(p+0x44));
    if (func_0203CD98()) func_02156DE0(0,0);
    if (*(void **)(p+0x10)) {
        func_021B9838(*(void **)(p+0x10));
        func_02156DC4(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}
