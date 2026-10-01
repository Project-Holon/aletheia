/*
 * function: func_021F3304
 * address: 0x021F3304
 * packet: pkt_ov194_021F3304
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
extern int func_02045770(int); extern int func_0201C6C4(int,int); extern void func_02045334(void *);
int func_021F3304(char *p) {
 int q;
 q=*(int *)(p+0xF8);
 if(*(unsigned char *)(p+0xF0)) {
 if(func_0201C6C4(q,func_02045770(*(int *)(p+0xEC)))==0) {
 func_02045334(*(void **)(p+0xEC));*(unsigned char *)(p+0xF0)=0;
 }}
 if(*(unsigned char *)(p+0xF0)==0)return 1;return 0;
}
