/*
 * function: func_021DF388
 * address: 0x021DF388
 * packet: pkt_ov183_021DF388
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DF3DA
 * symbols:
 *   func_021DF5B8 0x021DF5B8 thumb ov183
 *   func_021FCE0C 0x021FCE0C thumb ov186
 *   func_021FCDE8 0x021FCDE8 thumb ov186
 *   func_020437AC 0x020437AC arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned short u16;
extern void func_021DF5B8(char *);
struct Obj020437AC;
struct WordSet;
extern int func_021FCE0C(char *p, unsigned field);
extern void *func_021FCDE8(void *, u16);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0201ED04(struct WordSet *p);
extern void func_021FCC80(char *p);
extern void func_0201F868(void *);
extern void func_02082BCC(void *, int, unsigned int);
void func_021DF388(char *p)
{
    unsigned int i;
    func_021DF5B8(p);
    for (i = 0; i < func_021FCE0C(*(void **)(p + 4), 3); i++) {
        func_020437AC(func_021FCDE8(*(void **)(p + 4), i));
    }
    func_0201ED04(*(void **)(p + 8));
    func_021FCC80(*(void **)(p + 4));
    func_0201F868(*(void **)p);
    func_02082BCC(p, 0, 0xD4);
}
