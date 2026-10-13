/*
 * function: func_021F4948
 * address: 0x021F4948
 * packet: pkt_ov112_021F4948
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 NNS_GfdResetVramTransferTaskQueue has no outside witness; the integrator owns it.
 * extent: two-byte padding at 0x021F498E.
 * blocker: C below reproduces prior ov091_func_021B6FEC.c DIFF, 8 bytes
 *   differ (loads and pool words swapped), scratch blocker-1.log.
 *   extern void NNSi_GfdResetVramTransferTaskQueue(void *);
 *   extern char d_02146B80[];
 *   void NNS_GfdResetVramTransferTaskQueue(void) { NNSi_GfdResetVramTransferTaskQueue(d_02146B80); }
 *   symbols: NNSi_GfdResetVramTransferTaskQueue 0x02061B5C arm; d_02146B80 0x02146B80 data a4.
 * symbols:
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   func_021F4F40 0x021F4F40 thumb ov112
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 active:1; u16 rest:15; u8 data[34]; } Record;
extern void NNS_GfdResetVramTransferTaskQueue(void);
extern void func_021F4F40(void **p);
extern void func_021F4D40(u8 *p, u8 *e);
extern u32 func_020307B0(void *p);
void func_021F4948(u8 *p)
{
    int i;
    NNS_GfdResetVramTransferTaskQueue();
    func_021F4F40(*(void **)(p+0xc));
    for(i=0;i<*(u16 *)(p+0x10);i++) {
        if ((*(Record **)(p+8))[i].active==1)
            func_021F4D40(p,(u8 *)(&(*(Record **)(p+8))[i]));
    }
    func_020307B0(*(void **)(p+8));
    func_020307B0(p);
}
