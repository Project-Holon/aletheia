/*
 * function: func_021EFF34
 * address: 0x021EFF34
 * packet: pkt_ov034_021EFF34
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021F0700 0x021F0700 thumb ov034
 *   func_021F0930 0x021F0930 thumb ov034
 *   func_021F01F8 0x021F01F8 thumb ov034
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021F0700(char *);
extern void func_021F0930(int *);
extern void func_021F01F8(void);
extern void func_020307B0(void *);
void func_021EFF34(char *p) { func_02030EAC((struct Node *)(*(unsigned *)(p+0x10c))); func_021F0700(p); func_021F0930((int *)p); func_021F01F8(); func_020307B0(p); }
