/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov225_021B95A0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Allocation/zero extent0x78 and stores prove the Work field offsets;
 * record14 has8 bytes before record1c (12 gave14 concrete differences).
 * 0203159C returns a consumed allocation in r0 here, despite legacy void C.
 * 0203064C keeps all three visible original call inputs including r2 size.
 * Approved empty callback98FC was filed/verified before iter3 resolved it.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9D18 0x021B9D18 thumb ov225
 *   func_021B98FC 0x021B98FC thumb ov225
 *   func_021BB2B4 0x021BB2B4 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Args { void *data; u32 flag; };
struct Work {
    u16 heap; u16 pad2; struct Args *args; void *data; void *task;
    u32 state; u8 record14[8]; void *record1c; u16 record20; u16 record22;
    u8 pad24[12]; void *record30; u16 record34; u16 record36; u16 record38;
    u8 pad3a[14]; u8 record48; u8 pad49; u16 record4a; u16 record4c; u16 record4e;
    u8 rest[40];
};
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void *func_021B9D18(void *,u16);
extern void func_0204047C(int,u16);
extern void func_021B98FC(void *,char *);
extern void *func_020056A0(void (*)(void *,char *),void *,u32);
extern void FADE_Start(u32,int,int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern char *func_021BB2B4(char *,char *);
int func_021B95A0(void *proc, void *unused, struct Args *args)
{
    struct Work *p;
    GFL_HEAP_CreateChildHeap(1,0x90,0x50000);
    p = PROCSYS_AllocProcWork(proc,0x78,0x90);
    func_02082BCC(p,0,0x78);
    p->heap = 0x90;
    p->args = args;
    args->flag = 1;
    p->data = func_021B9D18(p->args->data,p->heap);
    func_0204047C(4,3);
    func_0204047C(5,2);
    func_0204047C(6,1);
    func_0204047C(7,0);
    p->task = func_020056A0(func_021B98FC,p,1);
    FADE_Start(3,16,0,0);
    GFL_NET_RestartWithDefaultTimeout(0,p->heap);
    p->record14[0] = 0;
    p->record20 = 0;
    p->record22 = 0;
    p->record30 = 0;
    p->record34 = 0;
    p->record36 = 0;
    p->record38 = 0;
    p->record48 = 1;
    p->record4a = 0;
    p->record4c = 0xffff;
    p->record4e = 0;
    p->state = 0;
    p->record1c = func_021BB2B4((char *)p->record14,p->data);
    return 1;
}
