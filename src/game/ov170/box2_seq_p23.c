/*
 * file:     box2_seq_p23.c
 * unit:     yes
 * function: func_021E99B0, func_021E9B74, func_021E9C94
 * address:  0x021E99B0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF4E4 0x021EF4E4 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EA75C 0x021EA75C thumb
 *   func_021EC61C 0x021EC61C thumb
 *   func_021DD1E8 0x021DD1E8 thumb
 *   func_021E01C4 0x021E01C4 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021E072C 0x021E072C thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EA770 0x021EA770 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   d_021EFA10 0x021EFA10 data a1
 *   func_02026124 0x02026124 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   data_021EF918 0x021EF918 data a1
 *   func_0202136C 0x0202136C thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E00C4 0x021E00C4 thumb
 */
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define HELD_WIN(p) (*(unsigned char *)(WORK(p) + 0x3DF6))
#define ITEM (*(unsigned short *)(p+0x10))
struct WinMgr;
struct Sound;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021ED588(char *p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *w, int a);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EA75C(int p);
extern void func_021EC61C(unsigned char *p);
extern void func_021DD1E8(char *p);
extern int func_021E01C4(char *p);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EF670(char *w);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021E072C(unsigned char *p);
extern void func_021ED75C(char **p, int i);
extern void func_021EE008(char *p, int a, int b);
extern void func_021ED594(char *p, unsigned i);
extern void func_021EA770(int p);
extern void func_021EF68C(char *w);
extern void func_021DEFEC(char *p, int b);
extern unsigned func_0202136C(unsigned short);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021ED55C(char **p, int flag);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021DD16C(unsigned char *p, int dir);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E00C4(char *p);
int func_021E99B0(unsigned char *p);
int func_021E9B74(unsigned char *p);
int func_021E9C94(char *p, int a, int n);
extern const unsigned char d_021EFA10[];
extern const unsigned char data_021EF918[];


#define WORK(p) (*(char **)((p) + 0x2C))


/*
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */
int func_021E99B0(unsigned char *p)
{
    switch (p[0x13]) {
    case 0:
        func_021EB988(p, d_021EFA10, 6);
        func_021EF4E4(MGR(p));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ED588((char *)p);
        return 0x11;
    case 1:
        func_021EB988(p, d_021EFA10, 6);
        func_021EF4E4(MGR(p));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ECB20((char *)p, 1, 1);
        func_021ED888(WORK(p), 0);
        func_021EE364((char **)p, 5, 10);
        func_021EA75C((int)p);
        func_021ED588((char *)p);
        return 0x1B;
    case 2:
        if (p[0x1B] == 1)
            func_021EC61C(p);
        func_021EE364((char **)p, 4, p[0x16]);
        func_021DD1E8((char *)p);
        while (func_021E01C4((char *)p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        p[0x16] = 0xFF;
        return 0x15;
    case 3:
        if (p[0x16] >= 0x1E) {
            func_021EC61C(p);
            func_021ECB84(WORK(p), p[0x16]);
        } else if (p[0x14] == p[0x17]) {
            func_021ECB84(WORK(p), p[0x16]);
        } else {
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        }
        func_021E072C(p);
        func_021ED75C((char **)p, 0x24);
        func_021EE364((char **)p, 4, p[0x1D]);
        func_021DD1E8((char *)p);
        while (func_021E01C4((char *)p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        if (p[0x1D] >= 0x22 && p[0x1D] <= 0x25)
            func_021EE008((char *)p, p[0x1D] - 0x22, 1);
        func_021ED594((char *)p, 0x24);
        return 0x15;
    case 4:
        func_021EA770((int)p);
        func_021EE364((char **)p, 6, p[0x16]);
        func_021EF68C(WORK(p));
        p[0x16] = 0xFF;
        return 0x20;
    case 5:
        func_021EA770((int)p);
        if (p[0x16] < 0x1E && p[0x14] != p[0x17])
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        else
            func_021ECB84(WORK(p), p[0x16]);
        func_021E072C(p);
        func_021ED75C((char **)p, 0x24);
        func_021EE364((char **)p, 6, p[0x1D]);
        func_021EF68C(WORK(p));
        func_021ED594((char *)p, 0x24);
        return 0x20;
    }
    return 0;
}

#undef WORK
#define WORK (*(char **)(p+0x2c))

int func_021E9B74(unsigned char *p)
{
    switch(p[0x13]) {
    case 0:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021EE364((char **)p,0xd,0x25); func_021ED588((char *)p); return 0x23;
    case 1:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021ECB20((char *)p,1,1); func_021ED888(WORK,0);
        func_021EE364((char **)p,0xe,0xa); func_021EA75C((int)p); func_021ED588((char *)p); return 0x27;
    case 4:
        func_021EA770((int)p); func_021EE364((char **)p,6,p[0x16]);
        func_02026124(*(void **)(WORK+0x70),0x27);
        p[0x16]=0xff; return 0x20;
    case 5:
        func_021EA770((int)p);
        if(p[0x16]<0x1e && p[0x14]!=p[0x17])
            func_021EC48C(p,p[0x17],p[0x16],*(unsigned char *)(WORK+0x3df6));
        else func_021ECB84(WORK,p[0x16]);
        func_021E072C(p); func_021ED75C((char **)p,0x24);
        func_021EE364((char **)p,6,p[0x1d]); func_02026124(*(void **)(WORK+0x70),0x27);
        func_021ED594((char *)p,0x24); return 0x20;
    }
    return 0;
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


int func_021E9C94(char *p, int a, int n)
{
    func_021DD16C((unsigned char *)p, 0);
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        if (a == 1)
            func_021EF670(WORK(p));
    }
    return func_021E8FC0(p, (int)func_021E00C4, n);
}
