/*
 * function: func_0218562C
 * address: 0x0218562C
 * packet: pkt_ov219_0218562C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048C4C is the non-C veneer ldr ip,[pc]; bx ip; .word 020307B0 (show 02048C4C..02048C58). All concrete bytes match, but the veneer call has no outside witness. Ilias owns ARM9; no overlay follower filed.
 * extent: lead ends 021856CC; unlabelled initialization follower 021856CC..02185728 is omitted while ARM9 blocks the caller.
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   d_02185E18 0x02185E18 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 index,member;} Entry;
extern const Entry d_02185E18[];
extern void func_02048AC4(void *);
extern void func_02048C4C(void *);
extern void func_02047738(void *);
extern void func_02047504(void *);
extern int func_020470D0(u32 *);
extern void func_02046EFC(void *);
void func_0218562C(char *p)
{
    u32 i;
    char *row;
    func_02048AC4(*(void **)(p+0xC36C));
    func_02048C4C(*(void **)(p+0xC370));
    func_02047738(*(void **)(p+0xC3A4));
    func_02047504(*(void **)(p+0xC38C));
    func_020470D0(*(u32 **)(p+0xC374));
    func_02046EFC(*(void **)(p+0xC374));
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*4;
        func_02047738(*(void **)(row+0xC3A8));
        func_02047504(*(void **)(row+0xC390));
        func_020470D0(*(u32 **)(row+0xC378));
        func_02046EFC(*(void **)(row+0xC378));
    }
    *(u32 *)(p+0xC3A4)=0;
}
