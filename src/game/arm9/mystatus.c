/*
 * file:     mystatus.c
 * unit:     yes
 * function: MYSTATUS_Create, MYSTATUS_Copy, MYSTATUS_Init, MYSTATUS_IsNameEmpty, MYSTATUS_CopyName, MYSTATUS_NameFromStrbuf, MYSTATUS_GetName, MYSTATUS_CopyNameChars, MYSTATUS_NameToStrbuf, MYSTATUS_CreateNameStrbuf, MYSTATUS_SetId, MYSTATUS_GetId, MYSTATUS_GetIdLow16, MYSTATUS_GetProfileId, MYSTATUS_SetProfileIdOnce, MYSTATUS_SetOutfitVariant, MYSTATUS_GetOutfitVariant, MYSTATUS_GetOutfit, MYSTATUS_SetOutfit, MYSTATUS_GetAvatarId, MYSTATUS_SetAvatarId, MYSTATUS_GetGender, MYSTATUS_SetGender, MYSTATUS_GetLanguage, MYSTATUS_GetVersion, MYSTATUS_SetLanguageAndVersion
 * address:  0x0200846C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from config.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   mystatus_file_name      0x020A70AC  data
 *   sub_0201F41C        0x0201F41C  thumb
 *   STRBUF_SetString        0x02045924  arm
 *   STRBUF_ToChars        0x02045A38  arm
 *   STRBUF_Create        0x020457B0  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   MI_CpuFill8   0x02082BCC  arm
 */
#include "config_shared_types.h"

struct Strbuf;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

/* The debug allocator: heap, size, clear, __FILE__ string, __LINE__. */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);

extern void STRBUF_SetString(struct Strbuf *strbuf, const u16 *src);

extern void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 n);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern char mystatus_file_name[];

void MYSTATUS_Init(struct MyStatus *mystatus);

void MYSTATUS_SetAvatarId(struct MyStatus *mystatus, u8 avatar_id);

void MYSTATUS_NameToStrbuf(const u16 *name, struct Strbuf *buf);

void *MYSTATUS_Create(int heap_id)
{
    struct MyStatus *mystatus = GFL_HEAP_Alloc((u16)heap_id, sizeof(struct MyStatus), 0, mystatus_file_name, 0x34);
    MYSTATUS_Init(mystatus);
    return mystatus;
}

void MYSTATUS_Copy(const struct MyStatus *src, struct MyStatus *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct MyStatus));
}

void MYSTATUS_Init(struct MyStatus *mystatus)
{
    MI_CpuFill8(mystatus, 0, sizeof(struct MyStatus));
    mystatus->gender = 2;
    MYSTATUS_SetAvatarId(mystatus, 0x15);
}

/* Non-zero when all eight name characters are zero. */
int MYSTATUS_IsNameEmpty(const struct MyStatus *mystatus)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (mystatus->name[i] != 0) {
            return 0;
        }
    }
    return 1;
}

/* The argument swap below is what -interworking produces for language tail call
 * to an extern whose instruction set the compiler cannot see: 0x0201F41C is
 * Thumb (odd pool word), 0x02045A38 is ARM (even), and the same code covers
 * both. */
void MYSTATUS_CopyName(u16 *dest, const u16 *src)
{
    sub_0201F41C(src, dest, 8);
}

void MYSTATUS_NameFromStrbuf(u16 *out, struct Strbuf *buf)
{
    STRBUF_ToChars(buf, out, 8);
}

const void *MYSTATUS_GetName(const void *mystatus)
{
    return mystatus;
}

void MYSTATUS_CopyNameChars(const u16 *src, u16 *dest, u32 n)
{
    sub_0201F41C(src, dest, n);
}

/* Also an argument-swapping tail call, 16 bytes instead of 12: the extra
 * `adds` is the third scratch register the swap needs when only two
 * arguments are live. */
void MYSTATUS_NameToStrbuf(const u16 *name, struct Strbuf *buf)
{
    STRBUF_SetString(buf, name);
}

/* heap_id is passed as int and narrowed here: a u16 parameter would be
 * truncated by the caller. */
struct Strbuf *MYSTATUS_CreateNameStrbuf(const u16 *name, int heap_id)
{
    struct Strbuf *buf = STRBUF_Create(8, (u16)heap_id);
    MYSTATUS_NameToStrbuf(name, buf);
    return buf;
}

void MYSTATUS_SetId(struct MyStatus *mystatus, u32 id)
{
    mystatus->id = id;
}

u32 MYSTATUS_GetId(const struct MyStatus *mystatus)
{
    return mystatus->id;
}

u16 MYSTATUS_GetIdLow16(const struct MyStatus *mystatus)
{
    return (u16)mystatus->id;
}

u32 MYSTATUS_GetProfileId(const struct MyStatus *mystatus)
{
    return mystatus->profile_id;
}

/* Set once: the store is skipped when the field is already non-zero. */
void MYSTATUS_SetProfileIdOnce(struct MyStatus *mystatus, u32 profile_id)
{
    if (mystatus->profile_id == 0) {
        mystatus->profile_id = profile_id;
    }
}

void MYSTATUS_SetOutfitVariant(struct MyStatus *mystatus, u8 outfit_variant)
{
    mystatus->outfit_variant = outfit_variant;
}

u8 MYSTATUS_GetOutfitVariant(const struct MyStatus *mystatus)
{
    return mystatus->outfit_variant;
}

u8 MYSTATUS_GetOutfit(const struct MyStatus *mystatus)
{
    return mystatus->outfit;
}

void MYSTATUS_SetOutfit(struct MyStatus *mystatus, u8 outfit)
{
    mystatus->outfit = outfit;
}

u8 MYSTATUS_GetAvatarId(const struct MyStatus *mystatus)
{
    return mystatus->avatar_id;
}

void MYSTATUS_SetAvatarId(struct MyStatus *mystatus, u8 avatar_id)
{
    mystatus->avatar_id = avatar_id;
}

u8 MYSTATUS_GetGender(const struct MyStatus *mystatus)
{
    return mystatus->gender;
}

void MYSTATUS_SetGender(struct MyStatus *mystatus, u8 gender)
{
    mystatus->gender = gender;
}

u8 MYSTATUS_GetLanguage(const struct MyStatus *mystatus)
{
    return mystatus->language;
}

u8 MYSTATUS_GetVersion(const struct MyStatus *mystatus)
{
    return mystatus->version;
}

void MYSTATUS_SetLanguageAndVersion(struct MyStatus *mystatus, u8 language, u8 version)
{
    mystatus->language = language;
    mystatus->version = version;
}
