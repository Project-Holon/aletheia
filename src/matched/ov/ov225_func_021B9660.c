/*
 * function: func_021B9660
 * address: 0x021B9660
 * packet: pkt_ov225_021B9660
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB308 0x021BB308 thumb ov225
 *   func_021BB7F4 0x021BB7F4 thumb ov225
 *   func_021BBA14 0x021BBA14 thumb ov225
 *   func_021BBAE8 0x021BBAE8 thumb ov225
 *   func_021B9DEC 0x021B9DEC thumb ov225
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
struct Node;
struct S020315D4;
extern void func_021BB308(char *p);
extern void func_021BB7F4(char *p);
extern void func_021BBA14(char *p);
extern void func_021BBAE8(char *p);
extern void func_021B9DEC(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(void *);
int func_021B9660(void *proc, void *a, void *b, char *work)
{
    switch (*(unsigned int *)(work + 16)) {
    case 0: func_021BB308(*(void **)(work + 28)); break;
    case 1: func_021BB7F4(*(void **)(work + 44)); break;
    case 2: func_021BBA14(*(void **)(work + 68)); break;
    case 3: func_021BBAE8(*(void **)(work + 116)); break;
    }
    func_02030EAC(*(void **)(work + 12));
    func_021B9DEC(*(void **)(work + 8));
    func_020315D4(proc);
    func_020306F0((void *)0x90);
    return 1;
}
