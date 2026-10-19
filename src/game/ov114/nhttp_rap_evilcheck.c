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
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   sNHTTPRapCryptoHeapId 0x021CE31C data a2
 *   sNHTTPRapEvilCheckEmptyString 0x021CE3B8 data a4
 *   sNHTTPRapEvilCheckFileName 0x021CE3A0 data a4
 *   OS_LockMutex  0x02086028  arm
 *   OS_InitMutex  0x02086004  arm  arm9
 *   WORDSET_CopyString  0x0201F41C  thumb  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 *   MYSTATUS_GetName  0x020084F4  thumb  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 *   MYSTATUS_GetNation  0x0200856C  thumb  arm9
 *   MYSTATUS_GetArea  0x02008570  thumb  arm9
 */
#include "../version.h"
#include "nhttp_types.h"
#include "nhttp_rap_types.h"

struct MYSTATUS;

extern void GF_PANIC_Fail(const char *,u32,const char *);

extern void MI_CpuFill8(void *,int,unsigned);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
struct MyStatus;

extern u8 MYSTATUS_GetNation(struct MyStatus *mystatus);

extern u8 MYSTATUS_GetArea(struct MyStatus *mystatus);

extern u32 MYSTATUS_GetId(struct MyStatus *mystatus);

extern const void *MYSTATUS_GetName(const void *p);

extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

u8 *NHTTP_RAP_EvilCheckAllocArray(int elemSize, int count, int heapId);

void NHTTP_RAP_EvilCheckFreeArray(void *buf);

void NHTTP_RAP_EvilCheckSetElement(u8 *base_p, const void *src_p, u32 elemSize, int index);

void *NHTTP_RAP_EvilCheckCryptoAlloc(int size);

void NHTTP_RAP_EvilCheckCryptoFree(void *p);

void NHTTP_RAP_InitTrainerInfo(NHTTPRapTrainerInfo *info_p, const struct MYSTATUS *mystatus_p);

extern u16 sNHTTPRapCryptoHeapId;

extern char sNHTTPRapEvilCheckEmptyString[], sNHTTPRapEvilCheckFileName[];
struct OSMutex;

/*
 * Allocates and zeroes an elemSize*count byte scratch block from tag 0xb9.
 */
u8 *NHTTP_RAP_EvilCheckAllocArray(int elemSize, int count, int heapId)
{
    int size = count * elemSize;
    u8 *p = GFL_HEAP_Alloc(heapId, size, 0, (const char *)0x021CE3A0, 0xb9);

    MI_CpuFill8(p, 0, size);
    return p;
}

void NHTTP_RAP_EvilCheckFreeArray(void *buf)
{
    GFL_HEAP_Free(buf);
}

void NHTTP_RAP_EvilCheckSetElement(u8 *base_p, const void *src_p, u32 elemSize, int index) { MI_CpuCopy8(src_p,base_p+elemSize*index,elemSize); }

void *NHTTP_RAP_EvilCheckCryptoAlloc(int size)
{
    void *p;
    if (sNHTTPRapCryptoHeapId == 0xffff)
        GF_PANIC_Fail(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    p = GFL_HEAP_Alloc(sNHTTPRapCryptoHeapId, size, 0, sNHTTPRapEvilCheckFileName, 0xe9);
    if (p == 0)
        GF_PANIC_Fail(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    return p;
}

void NHTTP_RAP_EvilCheckCryptoFree(void *block)
{
    GFL_HEAP_Free(block);
}

void NHTTP_RAP_InitTrainerInfo(NHTTPRapTrainerInfo *info_p, const struct MYSTATUS *mystatus_p)
{
    MI_CpuFill8(info_p, 0, 0x64);
    info_p->packetType = PM_VERSION_ID;
    info_p->version = 2;
    info_p->language = MYSTATUS_GetNation((struct MyStatus *)mystatus_p);
    info_p->romVersion = MYSTATUS_GetArea((struct MyStatus *)mystatus_p);
    info_p->trainerId = MYSTATUS_GetId((struct MyStatus *)mystatus_p);
    WORDSET_CopyString(MYSTATUS_GetName(mystatus_p), info_p->name, 8);
    info_p->reserved18 = 0;
    info_p->reserved24 = 0;
    info_p->reserved5c = 0;
}

#pragma thumb off

extern void OS_InitMutex(struct OSMutex *mutex);

extern void OS_LockMutex(struct OSMutex *mutex);

void NHTTPi_InitMutex(int *mutex_p);

void NHTTPi_LockMutexThunk(int *mutex_p);

void NHTTPi_InitMutex(int *mutex_p)
{
    OS_InitMutex((struct OSMutex *)mutex_p);
}

/*
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of NHTTPi_lockReqList (pkt_021B9500).
 */
void NHTTPi_LockMutexThunk(int *mutex_p)
{
    OS_LockMutex((struct OSMutex *)mutex_p);
}
