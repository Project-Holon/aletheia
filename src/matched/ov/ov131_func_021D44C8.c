/*
 * unit: yes
 * function: func_021D44C8,func_021D46E4
 * address: 0x021D44C8
 * packet: pkt_ov131_021D44C8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 02035CB8 writes fields only on success; their previous values
 *   remain initialized on failure. 021D5BAC guards a null output pointer.
 *   Tick difference is unsigned full-word arithmetic then byte truncation.
 *   Follower 021D46E4 is the complete eight-byte no-argument tail stub
 *   to owner 0204A648 (void(void)), with no return consumed.
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021D5DC4 0x021D5DC4 thumb ov131
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_021D5280 0x021D5280 thumb ov131
 *   func_021D6614 0x021D6614 thumb ov131
 *   func_021D52A8 0x021D52A8 thumb ov131
 *   func_021D7B48 0x021D7B48 thumb ov131
 *   func_021D9740 0x021D9740 thumb ov131
 *   func_021D8830 0x021D8830 thumb ov131
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02014D2C 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_021D5650 0x021D5650 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_021D5DC4(void *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
struct Actor;
struct McssSys;
struct Obj;
struct PrintSys;
extern u32 func_0204B98C(struct Actor *a);
extern void func_021D5280(char *p);
extern void func_021D6614(void *,void *);
extern void func_021D52A8(char *p);
extern void func_021D7B48(void *,void *);
extern void func_021D9740(void *,void *);
extern void func_021D8830(u8 *,u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02014C08(char *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02014D2C(struct McssSys *sys);
extern void func_02047970(void);
extern void func_02041EE4(u32,u32,u32);
extern int func_021D5BAC(u8 *,int,u16 *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D5650(void *);
int func_021D44C8(char *p)
{
    u32 tick;
    *(u32 *)(p+0x30)=*(u32 *)(p+0x28);
    *(u32 *)(p+0x34)=*(u32 *)(p+0x2c);
    func_02035CB8((u32 *)(p+0x28),(u32 *)(p+0x2c));
    switch (*(u32 *)(p+0x50)) {
    case 0:
        if (*(int *)(p+0xc)==1) func_021D5DC4(p);
        else {
            func_0202208C(0,1,1,0,6,1,*(u16 *)p);
            *(int *)(p+0x50)=1;
        }
        break;
    case 1:
        if (func_020221A4()==1) *(int *)(p+0x50)=4;
        break;
    case 2:
        if (*(void **)(p+0x1a0)==0 || func_0204B98C(*(void **)(p+0x1a0))==0 || *(int *)(*(char **)(p+8)+0x24)==1) {
            func_0202208C(0,0,0,0,6,1,*(u16 *)p);
            *(int *)(p+0x50)=3;
        }
        break;
    case 3:
        if (func_020221A4()==1) return *(int *)(p+0x54);
        break;
    case 4:
        func_021D5280(p);
        if (*(int *)(p+0xc)==1) func_021D5DC4(p);
        else {
            func_021D6614(p,*(void **)(p+0x88));
            if (*(int *)(*(char **)(p+8)+0x24)==1) {
                *(int *)(p+0x54)=1;
                *(int *)(p+0x50)=2;
            }
            func_021D52A8(p);
            if (*(int *)(p+0xc)==0) {
                switch (*(u32 *)(p+0x5c)) {
                case 0: func_021D7B48(p,*(void **)(p+0x8c)); break;
                case 1:
                case 3: func_021D9740(p,*(void **)(p+0x90)); break;
                case 2: func_021D8830((u8 *)p,*(u8 **)(p+0x94)); break;
                }
            }
        }
        break;
    }
    func_0201C4E4(*(void **)(p+0x84));
    func_0204A600();
    func_02014C08(*(char **)(p+0x78));
    func_02047964();
    func_020479D8();
    func_02014D2C(*(void **)(p+0x78));
    func_02047970();
    tick=*(u32 *)0x02fffc3c;
    *(u8 *)(p+0x1b)+=(u8)(tick-*(u32 *)(p+0x20));
    *(u32 *)(p+0x20)=tick;
    while (*(u8 *)(p+0x1b)>=4) {
        func_02041EE4(3,1,1);
        func_02041EE4(3,4,1);
        func_02041EE4(7,1,1);
        func_02041EE4(7,4,1);
        *(u8 *)(p+0x1b)-=4;
    }
    if (*(int *)(p+0x48)==1 && func_0204B98C(*(void **)(p+0x188))==0) {
        if (func_021D5BAC((u8 *)p,0,0)==1) func_0204B878(*(void **)(p+0x188),3);
        else func_0204B878(*(void **)(p+0x188),17);
        *(int *)(p+0x48)=0;
    }
    if (*(int *)(p+0x4c)==1 && func_0204B98C(*(void **)(p+0x18c))==0) {
        if (func_021D5BAC((u8 *)p,1,0)==1) func_0204B878(*(void **)(p+0x18c),2);
        else func_0204B878(*(void **)(p+0x18c),16);
        *(int *)(p+0x4c)=0;
    }
    func_021D5650(p);
    return 0;
}


extern void func_0204A648(void);
void func_021D46E4(void) { func_0204A648(); }
