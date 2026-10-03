/*
 * function: func_02212E74
 * address: 0x02212E74
 * packet: pkt_ov199_02212E74
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022135CC 0x022135CC thumb ov199
 *   func_02213684 0x02213684 thumb ov199
 *   func_0200BA58 0x0200BA58 thumb
 *   func_021EEE78 0x021EEE78 thumb ov188
 *   func_0200BA68 0x0200BA68 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_022133E4 0x022133E4 thumb ov199
 *   func_0201A354 0x0201A354 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020130DC 0x020130DC thumb
 *   func_02213808 0x02213808 thumb ov199
 */
typedef unsigned char u8;
typedef struct Flag { u8 bit:1; u8 rest:7; } Flag;
typedef struct Bytes { u8 a,b,c; } Bytes;
extern void func_022135CC(u8 *,u8 *,u8 *);
extern void func_02213684(const u8 *,u8 *,u8 *);
extern void func_0200BA58(void);
extern void func_021EEE78(void *);
extern void func_0200BA68(void);
typedef signed int     s32;
typedef unsigned int   u32;
struct Big;
struct Rec160;
struct Reg2;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200AE14(void *);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern void func_022133E4(u8 *p, void *party1, void *party2, u8 *save, void *reg, int setting, u8 *record, void *other, int mode);
extern void *func_0201A354(int,int);
extern void func_020307B0(void *);
extern void func_020130DC(void *);
extern void func_02213808(char *p, int value);
int func_02212E74(void *manager, u8 *arg, u8 *p)
{
    u8 *record = *(u8 **)(arg + 4);
    int state = *(int *)(arg + 0xc);
    Bytes bytes;
    void *rules,*reg,*created;
    int setting;
    *(unsigned *)(p + 0x1b8) = *(unsigned *)(record + 4);
    *(unsigned *)(p + 0x1b4) = *(unsigned *)(record + 0x8c);
    *(unsigned *)(p + 0x1c4) = ((Flag *)(record + 0xc1))->bit;
    *(unsigned *)(p + 0x1b4) = *(unsigned *)(record + 0x8c);
    func_022135CC(*(u8 **)(arg + 4), &bytes.b, &bytes.c);
    p[0x1bc] = bytes.c;
    func_02213684(*(u8 **)(arg + 4), &bytes.a, p + 0x1bd);
    func_0200BA58();
    func_021EEE78(*(void **)(arg + 4));
    func_0200BA68();
    if (*(int *)(p + 0x1c) == 0) {
        rules = func_0200B1D4(func_0200B358(func_02012EBC(*(void **)(p + 4))),0);
        reg = func_0200AE14(rules);
        setting = func_0200B078(rules,2);
        if (state == 0) func_022133E4(p + 0x1d0,*(void **)(p + 0x30),*(void **)(p + 0x34),*(void **)(p + 0x2c),reg,setting,record,p + 0x1b4,0);
    } else if (*(int *)(p + 0x1c) == 2) {
        created = func_0201A354(*(int *)(p + 8) + 0xf,0x56);
        if (state == 0) func_022133E4(p + 0x1d0,*(void **)(p + 0x30),*(void **)(p + 0x34),*(void **)(p + 0x2c),created,0,record,p + 0x1b4,2);
        func_020307B0(created);
    }
    func_020130DC(*(void **)(arg + 4));
    func_020307B0(*(void **)(arg + 4));
    func_020307B0(*(void **)(arg + 8));
    func_020307B0(arg);
    if (*(int *)(p + 0x1c) == 1) {
        switch(state) {
        case 0: func_02213808(manager,0);break;
        case 1: *(int *)(p + 0x1c0)=1;func_02213808(manager,0);break;
        }
    } else {
        switch(state) {
        case 0: *(int *)(p + 0x20)=1;func_02213808(manager,1);break;
        case 2: *(int *)(p + 0x220)=1;func_02213808(manager,4);break;
        case 3: *(int *)(p + 0x20)=2;func_02213808(manager,1);break;
        }
    }
    return 1;
}
