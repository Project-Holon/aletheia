/*
 * file:     nhttp_rap_evilcheck.c
 * unit:     yes
 * function: NHTTP_RAP_EvilCheckAllocArray, NHTTP_RAP_EvilCheckFreeArray, NHTTP_RAP_EvilCheckSetElement, NHTTP_RAP_EvilCheckCryptoAlloc, NHTTP_RAP_EvilCheckCryptoFree, NHTTP_RAP_InitTrainerInfo, NHTTPi_InitMutex, NHTTPi_LockMutexThunk
 * address:  0x021B9A64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Cut from nhttp_rap.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   sNHTTPRapCryptoHeapId 0x021CE31C data a2
 *   sNHTTPRapEvilCheckEmptyString 0x021CE3B8 data a4
 *   sNHTTPRapEvilCheckFileName 0x021CE3A0 data a4
 *   func_02086028  0x02086028  arm
 */
#include "nhttp_types.h"
#include "nhttp_rap_types.h"

struct MYSTATUS;

extern void func_02034714(const char *,u32,const char *);

extern void MI_CpuFill8(void *,int,unsigned);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u8 func_0200856C(const struct MYSTATUS *mystatus_p);

extern u8 func_02008570(const struct MYSTATUS *mystatus_p);

extern u32 func_02008530(const struct MYSTATUS *mystatus_p);

extern const void *func_020084F4(const void *p);

extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);

u8 *NHTTP_RAP_EvilCheckAllocArray(int elemSize, int count, int heapId);

void NHTTP_RAP_EvilCheckFreeArray(void *buf);

void NHTTP_RAP_EvilCheckSetElement(u8 *base_p, const void *src_p, u32 elemSize, int index);

void *NHTTP_RAP_EvilCheckCryptoAlloc(int size);

void NHTTP_RAP_EvilCheckCryptoFree(void *p);

void NHTTP_RAP_InitTrainerInfo(NHTTPRapTrainerInfo *info_p, const struct MYSTATUS *mystatus_p);

extern u16 sNHTTPRapCryptoHeapId;

extern char sNHTTPRapEvilCheckEmptyString[], sNHTTPRapEvilCheckFileName[];

/*
 * Allocates and zeroes an elemSize*count byte scratch block from tag 0xb9.
 */
u8 *NHTTP_RAP_EvilCheckAllocArray(int elemSize, int count, int heapId)
{
    int size = count * elemSize;
    u8 *p = func_02030734(heapId, size, 0, (const char *)0x021CE3A0, 0xb9);

    MI_CpuFill8(p, 0, size);
    return p;
}

void NHTTP_RAP_EvilCheckFreeArray(void *buf)
{
    func_020307B0(buf);
}

void NHTTP_RAP_EvilCheckSetElement(u8 *base_p, const void *src_p, u32 elemSize, int index) { MI_CpuCopy8(src_p,base_p+elemSize*index,elemSize); }

void *NHTTP_RAP_EvilCheckCryptoAlloc(int size)
{
    void *p;
    if (sNHTTPRapCryptoHeapId == 0xffff)
        func_02034714(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    p = func_02030734(sNHTTPRapCryptoHeapId, size, 0, sNHTTPRapEvilCheckFileName, 0xe9);
    if (p == 0)
        func_02034714(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    return p;
}

void NHTTP_RAP_EvilCheckCryptoFree(void *p)
{
    func_020307B0(p);
}

void NHTTP_RAP_InitTrainerInfo(NHTTPRapTrainerInfo *info_p, const struct MYSTATUS *mystatus_p)
{
    MI_CpuFill8(info_p, 0, 0x64);
    info_p->packetType = 0x15;
    info_p->version = 2;
    info_p->language = func_0200856C(mystatus_p);
    info_p->romVersion = func_02008570(mystatus_p);
    info_p->trainerId = func_02008530(mystatus_p);
    func_0201F41C(func_020084F4(mystatus_p), info_p->name, 8);
    info_p->reserved18 = 0;
    info_p->reserved24 = 0;
    info_p->reserved5c = 0;
}

#pragma thumb off

extern void func_02086004(int *mutex_p);

extern void func_02086028(int *mutex_p);

void NHTTPi_InitMutex(int *mutex_p);

void NHTTPi_LockMutexThunk(int *mutex_p);

void NHTTPi_InitMutex(int *mutex_p)
{
    func_02086004(mutex_p);
}

/*
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of NHTTPi_lockReqList (pkt_021B9500).
 */
void NHTTPi_LockMutexThunk(int *mutex_p)
{
    func_02086028(mutex_p);
}
