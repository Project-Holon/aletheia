/*
 * function: func_021DCFF4
 * address: 0x021DCFF4
 * packet: pkt_ov171_021DCFF4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021DE8A8 0x021DE8A8 thumb ov171
 *   func_021DD51C 0x021DD51C thumb ov171
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD500 0x021DD500 thumb ov171
 */
typedef signed char s8;
typedef unsigned short u16;
extern int func_0201C6B4(void *);
extern int func_021DE8A8(char *);
extern int func_021DD51C(char *,s8);
extern void func_020061E4(int);
extern int func_021DD500(char *,int,int,int);
int func_021DCFF4(char *p) {
    int choice;
    if (!func_0201C6B4(*(void **)(p+0xb6c))) return 4;
    choice=func_021DE8A8(p);
    switch(choice) {
    case 0:
        if (func_021DD51C(p,-1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,12,12,5);
        }
        break;
    case 1:
        if (func_021DD51C(p,1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,13,13,5);
        }
        break;
    case 2:
        func_020061E4(0x556);
        *(u16 *)(*(char **)p+6)=1;
        return func_021DD500(p,14,8,10);
    case 3:
        func_020061E4(0x551);
        *(u16 *)(*(char **)p+6)=0;
        return func_021DD500(p,15,9,10);
    case 4:
        func_020061E4(0x54c);
        *(s8 *)(p+0xc5d)=*(s8 *)(p+0xc5c);
        return 6;
    case 5: case 6: case 7: case 8: case 9: case 10:
        *(s8 *)(p+0xc5d)=choice-5;
        func_020061E4(0x54c);
        return 6;
    }
    return 4;
}
