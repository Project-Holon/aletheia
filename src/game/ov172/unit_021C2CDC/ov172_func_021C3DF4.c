/*
 * function: func_021C3DF4
 * address:  0x021C3DF4
 * packet:   pkt_ov172_021C3DF4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      jpeg_encode_main (libssp.TWL.HYB.a(exifenc.o))
 *
 * notes: EXACT 2026-10-01 (lane29), was 22 B. The old `g_021CADF0` struct is
 *   the object's separate .bss statics anchored at dateTimeDataFlag
 *   (encode_file_size +4, SSPiEncodeSignCheckMode +8 (global),
 *   SSPiSoftwareSize +0xc, SSPiMakerNoteUserBufferSize +0x10, dst +0x14,
 *   SSPiMakerNoteBufferSize +0x18, SSPiMakerNoteBuffer +0x1c,
 *   SSPiMakerNoteUserBuffer +0x20, dateTimeData +0x24, SSPiSoftware +0x38).
 *   Defining them as file statics fixed the count0++ / SSPiSoftwareSize test
 *   order at +0x204. 1.1p1 .bss layout for the 4-byte group: the first
 *   declared stays at offset 0, the rest are laid out in reverse declaration
 *   order; arrays follow in declaration order. Locals are still the old
 *   stand-ins (DWARF: jexif, cfg_encode_exif, 28 block-scoped `entry`).
 *
 * symbols:
 *   g_021CAE48 0x021CAE48 data ov172
 *   g_021CB728 0x021CB728 data
 *   g_021CC070 0x021CC070 data ov172
 *   g_021CAEE8 0x021CAEE8 data ov172
 *   g_021CB308 0x021CB308 data ov172
 *   g_021CBBA0 0x021CBBA0 data ov172
 *   g_021C8894 0x021C8894 data ov172
 *   g_021C88A0 0x021C88A0 data ov172
 *   dateTimeDataFlag 0x021CADF0 data ov172
 *   encode_file_size 0x021CADF4 data ov172
 *   SSPiEncodeSignCheckMode 0x021CADF8 data ov172
 *   SSPiSoftwareSize 0x021CADFC data ov172
 *   SSPiMakerNoteUserBufferSize 0x021CAE00 data ov172
 *   dst 0x021CAE04 data ov172
 *   SSPiMakerNoteBufferSize 0x021CAE08 data ov172
 *   SSPiMakerNoteBuffer 0x021CAE0C data ov172
 *   SSPiMakerNoteUserBuffer 0x021CAE10 data ov172
 *   dateTimeData 0x021CAE14 data ov172
 *   SSPiSoftware 0x021CAE28 data ov172
 *   g_021C88AC 0x021C88AC data ov172
 *   g_021C88B4 0x021C88B4 data ov172
 *   g_021CAE90 0x021CAE90 data
 *   g_021CAEC6 0x021CAEC6 data ov172
 *   g_021C88BC 0x021C88BC data ov172
 *   g_021C88C0 0x021C88C0 data ov172
 *   write_exif_ifd_tables 0x021C3A28 arm ov172
 */

#include "../../../matched/include/G_Ae90.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
struct Slot
{
  u16 tag;
  u16 type;
  u32 count;
  s8 field8;
  u8 pad9;
  s16 fieldA;
  u32 fieldC;
  u32 field10;
  u32 field14;
  u8 field18[30];
  char str[30];
  u32 field54;
};
struct SlotManager
{
  struct Slot *ptr0;
  s16 count0;
  u16 pad6;
  u32 field8;
  struct Slot *ptrC;
  s16 count1;
  u16 pad12;
  u32 field14;
  struct Slot *ptr18;
  s16 count2;
  u16 pad1E;
  u32 field20;
  struct Slot *ptr24;
  s16 count3;
  u16 pad2A;
  u32 field2C;
  struct Slot *ptr30;
  s16 count4;
  u16 pad36;
  u32 field38;
  u32 pad3C[2];
  u32 field44;
};
struct UnkObj
{
  u32 field0;
  u32 len;
  u32 field8;
  u32 fieldC;
  u32 field10;
  u8 *buffer;
  u32 field18;
};
extern struct SlotManager g_021CAE48;
extern struct Slot g_021CB728[];
extern struct Slot g_021CC070[];
extern struct Slot g_021CAEE8[];
extern struct Slot g_021CB308[];
extern struct Slot g_021CBBA0[];
extern const char g_021C8894[];
extern const char g_021C88A0[];
static int dateTimeDataFlag = 0;
static u8 *SSPiMakerNoteUserBuffer = 0;
static u8 *SSPiMakerNoteBuffer = 0;
static u32 SSPiMakerNoteBufferSize = 0;
static u8 *dst = 0;
static u32 SSPiMakerNoteUserBufferSize = 0;
static u32 SSPiSoftwareSize = 0;
int SSPiEncodeSignCheckMode = 0;
static u32 encode_file_size = 0;
static char dateTimeData[20] = {0};
static char SSPiSoftware[30] = {0};

extern const char g_021C88AC[];
extern const char g_021C88B4[];
extern struct Ae90 g_021CAE90;
extern const char g_021CAEC6[];
extern const char g_021C88BC[];
extern const char g_021C88C0[];
extern void STD_CopyLString(char *dst, const char *src, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 write_exif_ifd_tables(struct SlotManager *mgr, u32 mode, u8 *thumb_src, u32 thumb_size);
s16 func_021C3DF4(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size)
{
  s16 cfg_encode_exif;
  s16 cfg_encode_gray_scale;
  s16 cfg_input_width;
  s16 cfg_input_height;
  struct SlotManager *sb = &g_021CAE48;
  struct Slot *s;
  s16 cfg_encode_exif_;
  sb->ptr0 = g_021CB728;
  sb->count0 = 0;
  sb->field8 = 0;
  sb->ptrC = g_021CC070;
  sb->count1 = 0;
  sb->field14 = 0;
  sb->ptr18 = g_021CAEE8;
  sb->count2 = 0;
  sb->field20 = 0;
  sb->ptr24 = g_021CB308;
  sb->count3 = 0;
  sb->field2C = 0;
  sb->ptr30 = g_021CBBA0;
  sb->count4 = 0;
  sb->field38 = 0;
  if (encode_option & 1)
  {
    cfg_encode_exif = 1;
  }
  else
  {
    cfg_encode_exif = 0;
  }
  cfg_encode_gray_scale = 0;
  cfg_input_width = width;
  cfg_input_height = height;
  sb->count0 = 0;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x010F;
  s->type = 2;
  s->count = 9;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, g_021C8894, 9);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0110;
  s->type = 2;
  s->count = 11;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88A0, 11);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  if (SSPiSoftwareSize != 0)
  {
    s = &sb->ptr0[sb->count0];
    s->tag = 0x0131;
    s->type = 2;
    s->count = SSPiSoftwareSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    func_0208CB10(s->str, SSPiSoftware, s->count);
    s->field54 = 0;
    sb->count0++;
  }
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0132;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0213;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  sb->count1 = 0;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(g_021C88AC, s->field18, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9003;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9004;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9101;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x927C;
  s->type = 7;
  s->count = 0;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(g_021C88B4, s->field18, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA001;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 1;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA002;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_width;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA003;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_height;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count2 = 0;
  sb->count1++;
  s = &sb->ptr18[sb->count2];
  s->tag = g_021CAE90.tag;
  s->type = g_021CAE90.type;
  s->count = g_021CAE90.count;
  s->field8 = g_021CAE90.f8;
  s->fieldA = g_021CAE90.fa;
  s->fieldC = g_021CAE90.fc;
  s->field10 = g_021CAE90.f10;
  s->field14 = g_021CAE90.f14;
  func_0208CB10(s->str, g_021CAEC6, s->count);
  s->field54 = 0;
  sb->count2++;
  if (SSPiMakerNoteBufferSize != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1001;
    s->type = 7;
    s->count = SSPiMakerNoteBufferSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  if (SSPiMakerNoteUserBufferSize != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1002;
    s->type = 7;
    s->count = SSPiMakerNoteUserBufferSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  sb->count3 = 0;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0001;
  s->type = 2;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88BC, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0002;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(g_021C88B4, s->field18, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x1000;
  s->type = 2;
  s->count = 18;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_0208CB10(s->str, g_021C88C0, 18);
  s->field54 = 0;
  sb->count4 = 0;
  sb->count3++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0103;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 6;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  cfg_encode_exif_ = cfg_encode_exif;
  sb->count4++;
  if (cfg_encode_exif_)
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteBufferSize != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteUserBufferSize != 0)
        {
          m->count += 12;
        }
        m->count = ((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = (u32) thumb_size;
    sb->count4++;
  }
  else
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteBufferSize != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteUserBufferSize != 0)
        {
          m->count += 12;
        }
        m->count = ((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = 0;
    sb->count4++;
  }
  dst[encode_file_size++] = 0xFF;
  dst[encode_file_size++] = 0xD8;
  if (cfg_encode_exif_)
  {
    if (write_exif_ifd_tables(sb, 0, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  else
  {
    if (write_exif_ifd_tables(sb, 1, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  if ((encode_file_size & 1) == 1)
  {
    dst[encode_file_size++] = 0;
  }
  return 1;
}
