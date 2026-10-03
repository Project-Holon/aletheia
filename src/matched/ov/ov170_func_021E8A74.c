/*
 * function: func_021E8A74
 * address:  0x021E8A74
 * packet:   pkt_ov170_021E8A74
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_02007A80 0x02007A80 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EBC28 0x021EBC28 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   d_021EF9C8 0x021EF9C8 data
 *   d_021EF93C 0x021EF93C data
 *   d_021EF964 0x021EF964 data
 *   d_021EF978 0x021EF978 data
 *   d_021EF98C 0x021EF98C data
 *   d_021EF9A0 0x021EF9A0 data
 *   d_021EF9E0 0x021EF9E0 data
 *   d_021EF928 0x021EF928 data
 *   d_021EF9F8 0x021EF9F8 data
 *
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */

struct WinMgr;
extern void func_021ED55C(unsigned char *p, int flag);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern int func_02007A80(void *save, unsigned bits);
extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021EBC28(unsigned char *p, int kind, int i);
extern void func_021EE364(unsigned char *p, int idx, int v);
typedef unsigned int   u32;
struct Sound;
extern void func_02026124(struct Sound *obj, u32 idx);
extern const unsigned char d_021EF9C8[];
extern const unsigned char d_021EF93C[];
extern const unsigned char d_021EF964[];
extern const unsigned char d_021EF978[];
extern const unsigned char d_021EF98C[];
extern const unsigned char d_021EF9A0[];
extern const unsigned char d_021EF9E0[];
extern const unsigned char d_021EF928[];
extern const unsigned char d_021EF9F8[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define KIND(p) (*(unsigned char *)(WORK(p) + 0xA17C))
#define SAVE(p) (*(void **)(*(char **)(p) + 4))

int func_021E8A74(unsigned char *p)
{
    int flag;

    switch (STEP(p)) {
    case 0:
        func_021ED55C(p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0x64);
    case 1:
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 1)
                func_021EB988(p, d_021EF9C8, 6);
            else
                func_021EB988(p, d_021EF93C, 5);
        } else if (KIND(p) == 1) {
            func_021EB988(p, d_021EF964, 5);
        } else if (KIND(p) == 2) {
            func_021EB988(p, d_021EF978, 5);
        } else if (KIND(p) == 3) {
            func_021EB988(p, d_021EF98C, 5);
        } else if (KIND(p) == 4) {
            func_021EB988(p, d_021EF9A0, 5);
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 1)
                func_021EB988(p, d_021EF9E0, 6);
            else
                func_021EB988(p, d_021EF928, 5);
        } else if (KIND(p) == 6) {
            func_021EB988(p, d_021EF9F8, 6);
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0x64);
    case 2:
        STEP(p) = 0;
        if (KIND(p) == 0)
            func_021EBC28(p, 2, 0x18);
        else
            func_021EBC28(p, 3, 0x18);
        flag = 0;
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 0)
                flag = 1;
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 0)
                flag = 1;
        } else if (KIND(p) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            func_021EE364(p, 0xB, 1);
            func_02026124(LIST(p), 0);
        } else {
            func_021EE364(p, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}
