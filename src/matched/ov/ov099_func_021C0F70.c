/*
 * function: func_021C0F70
 * address: 0x021C0F70
 * packet: pkt_ov099_021C0F70
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: 0x0203C5EC ARM verified EXACT 20 bytes in blocker-c5ec-one.log.
 *   extern char *d_021469DC;
 *   int func_0203C5EC(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data a4.
 * blocker: ov009 02156D5C is code in matched unit ov009_func_02156CF4.c,
 *   but its function: header lists only CF4; no duplicate leaf permitted.
 * extent-policy: no follower C filed while ARM9 also blocks this caller.
 * extent: 236-byte lead followed by two 4-byte return-r1 stubs at 105C/1060.
 * prototype: D7B0/D7BC preserve the caller's visible integer input through veneers.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_0203C3EC 0x0203C3EC arm
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_02156D5C 0x02156D5C thumb ov009
 *   func_0203C5EC 0x0203C5EC arm
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
extern int func_021BA928(void *);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *, int);
typedef unsigned char  u8;
extern void func_021B9AE0(void *w, u8 *s);
extern int func_0203C3EC(void);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern unsigned func_02156D5C(void);
extern int func_0203C5EC(void);
extern int func_021C282C(unsigned char *);
extern void func_021BE6E4(char *);
extern unsigned char func_021BDD48(char *, void *);
extern void func_021BA8EC(char *);
extern void func_021BA7D8(void *p);
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
int func_021C0F70(char *p, int ret)
{
    void *selection;
    func_021BA928(p);
    if (--*(int *)(p + 0x1c4) < 0) {
        selection = func_021BE2A8(p, func_021B97F4(p + 0x274));
        if (selection) func_021B9AE0(p + 0x274, selection);
        *(int *)(p + 0x1cc) = 61;
    } else if (func_0203C3EC() == 5) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_02156D5C() == 5) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 12, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_02156D5C() == 4 || func_0203C5EC() != 0) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (func_0203C3EC() == 1) {
        func_021C282C(*(unsigned char **)(p + 8));
        func_021BE6E4(p);
        func_021BDD48(p, *(void **)(p + 8));
        *(int *)(p + 0x1cc) = 41;
        func_021BA8EC(p);
        func_021BA7D8(p);
        *(int *)(p + 0x1e0) = 30;
        func_0203D7B0(1);
        func_0203D7BC(1);
    }
    return ret;
}
