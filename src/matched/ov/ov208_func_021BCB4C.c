/*
 * function: func_021BCB4C
 * address: 0x021BCB4C
 * packet: pkt_ov208_021BCB4C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 102 code bytes, then two zero alignment bytes at 021BCBB2.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_021BC26C 0x021BC26C thumb ov208
 *   func_020307B0 0x020307B0 arm
 *   func_021BC39C 0x021BC39C thumb ov208
 *   func_021BE778 0x021BE778 thumb ov208
 *   func_021BD954 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BCEC0 0x021BCEC0 thumb ov208
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
extern void func_0204E720(unsigned,int,int,int);
extern void func_021BC26C(void *);
struct PrintSys;
extern void func_020307B0(void *p);
extern void func_021BC39C(void *);
struct Node;
struct Ov208Mgr;
struct PrintSys;
struct S020315D4;
extern void func_021BE778(struct Ov208Mgr *m);
extern void func_021BD954(struct Ov208Mgr *m);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *);
extern void func_021BCEC0(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021BCB4C(void *a,int b,int c,char *p)
{
    func_0204E720(3,16,16,0);
    if(*(void **)(p+0x20))func_021BC26C(*(void **)(p+0x20));
    if(*(unsigned *)(p+0x24))func_020307B0((void *)(*(unsigned *)(p+0x24)));
    func_021BC39C(*(void **)(p+0x1c));
    func_021BE778(*(void **)(p+0x18));
    func_021BD954(*(void **)(p+0x14));
    func_02030EAC(*(void **)(p+0x10));
    func_0201C6EC((struct PrintSys *)(*(unsigned *)(p+0xc)));
    func_0201C4C0(*(void **)(p+0xc));
    func_0201D83C(*(void **)(p+8));
    func_021BCEC0(*(char **)(p+4));
    func_020315D4(a);
    func_020306F0(149);
    return 1;
}
