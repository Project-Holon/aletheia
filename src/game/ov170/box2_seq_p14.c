/*
 * file:     box2_seq_p14.c
 * unit:     yes
 * function: func_021E63B0, func_021E6418
 * address:  0x021E63B0
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
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 */
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
struct WinMgr;
struct Sound;
struct Struct_02025CD0;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_020061E4(unsigned);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021DD14C(char *p);
extern void func_021DF0BC(unsigned char *);
extern void func_021DEFEC(char *p, int b);
extern void func_021EBA5C(char *, int);
extern void func_021ED6E4(char **p, int v);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021ED508(unsigned char *, int, int);
extern void func_021ED888(char *, int);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EC000(char *, int, int);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EA83C(char *p, int a);
extern int func_021E8F50(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
int func_021E63B0(unsigned char *p);
int func_021E6418(u8 *p);

int func_021E63B0(unsigned char *p)
{
    int r;
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    if (p[0x16] < 0x1e) {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021EF670(WORK(p));
        r = 0x39;
    } else {
        func_020260E4(OBJ(p), p[0x16] - 0x1e);
        func_021EE3E4((char **)p, p[0x16] - 0x1e);
        func_021EF68C(WORK(p));
        r = 0x46;
    }
    func_021ED55C((char **)p, 1);
    func_021ED508(p, 0xe, 1);
    return r;
}

/*
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int func_021E6418(u8 *p){int sel;sel=37;if(*(u16 *)(*(char **)(p+0x2c)+0xa16c)!=0)sel=36;func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),sel);func_021EE3E4((char **)p,sel);func_021ED55C((char **)p,1);return 57;}
