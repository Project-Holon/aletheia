/*
 * function: func_021C3DF4
 * address:  0x021C3DF4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CAE48 0x021CAE48 data ov172
 *   g_021CB728 0x021CB728 data ov172
 *   g_021CC070 0x021CC070 data ov172
 *   g_021CAEE8 0x021CAEE8 data ov172
 *   g_021CB308 0x021CB308 data ov172
 *   g_021CBBA0 0x021CBBA0 data ov172
 *   g_021C8894 0x021C8894 data ov172
 *   g_021C88A0 0x021C88A0 data ov172
 *   g_021CADF0 0x021CADF0 data ov172
 *   g_021CAE28 0x021CAE28 data ov172
 *   g_021CAE14 0x021CAE14 data ov172
 *   g_021C88AC 0x021C88AC data ov172
 *   g_021C88B4 0x021C88B4 data ov172
 *   g_021CAE90 0x021CAE90 data ov172
 *   g_021CAEC6 0x021CAEC6 data ov172
 *   g_021C88BC 0x021C88BC data ov172
 *   g_021C88C0 0x021C88C0 data ov172
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Slot {
    u16 tag;
    u16 type;
    u32 count;
    s8  field8;
    u8  pad9;
    s16 fieldA;
    u32 fieldC;
    u32 field10;
    u32 field14;
    u8  field18[30];
    char str[30];
    u32 field54;
};

struct SlotManager {
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

struct UnkObj {
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
extern struct UnkObj g_021CADF0;
extern const char g_021CAE28[];
extern const char g_021CAE14[];
extern const char g_021C88AC[];
extern const char g_021C88B4[];
extern struct Slot g_021CAE90;
extern const char g_021CAEC6[];
extern const char g_021C88BC[];
extern const char g_021C88C0[];

extern void STD_CopyLString(char *dst, const char *src, u32 n);
extern void MI_CpuCopy8(void *dst, const void *src, u32 n);
extern u32 write_exif_ifd_tables(struct SlotManager *mgr, u32 mode, u32 arg3, void *arg4);

u32 func_021C3DF4(void *arg0, void *arg1, u32 flags, u32 arg3, void *arg4)
{
    s16 is_flag;
    struct SlotManager *sb = &g_021CAE48;
    struct Slot *s;
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

    sb->count0 = 0;
    is_flag = (flags & 1) != 0;

    // Tag 0: Make
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

    // Tag 1: Model
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

    // Tag 2: XResolution
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

    // Tag 3: YResolution
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

    // Tag 4: ResolutionUnit
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

    // Tag 5: Software
    sb->count0++;
    if (g_021CADF0.fieldC != 0) {
        s = &sb->ptr0[sb->count0];
        s->tag = 0x0131;
        s->type = 2;
        s->count = g_021CADF0.fieldC;
        s->field8 = 0;
        s->fieldA = 0;
        s->fieldC = 0;
        s->field10 = 0;
        s->field14 = 0;
        func_0208CB10(s->str, g_021CAE28, s->count);
        s->field54 = 0;
        sb->count0++;
    }

    // Tag 6: DateTime
    s = &sb->ptr0[sb->count0];
    s->tag = 0x0132;
    s->type = 2;
    s->count = 20;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    func_0208CB10(s->str, g_021CAE14, 20);
    s->field54 = 0;

    // Tag 7: YCbCrPositioning
    sb->count0++;
    s = &sb->ptr0[sb->count0];
    s->tag = 0x0213;
    s->type = 3;
    s->count = 1;
    s->field8 = 0;
    s->fieldA = 1;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;

    sb->count0++;

    // Sub-table 1 (Exif IFD)
    sb->count1 = 0;

    // Tag 9: ExifVersion
    s = &sb->ptrC[sb->count1];
    s->tag = 0x9000;
    s->type = 7;
    s->count = 4;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    MI_CpuCopy8(s->field18, g_021C88AC, 4);
    s->field54 = 0;

    // Tag 10: DateTimeOriginal
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
    func_0208CB10(s->str, g_021CAE14, 20);
    s->field54 = 0;

    // Tag 11: DateTimeDigitized
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
    func_0208CB10(s->str, g_021CAE14, 20);
    s->field54 = 0;

    // Tag 12: ComponentsConfiguration
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

    // Tag 13: MakerNote
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

    // Tag 14: FlashPixVersion
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
    func_02082EA4(s->field18, g_021C88B4, 4);
    s->field54 = 0;

    // Tag 15: ColorSpace
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

    // Tag 16: PixelXDimension
    sb->count1++;
    s = &sb->ptrC[sb->count1];
    s->tag = 0xA002;
    s->type = 4;
    s->count = 1;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = (u32)arg0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;

    // Tag 17: PixelYDimension
    sb->count1++;
    s = &sb->ptrC[sb->count1];
    s->tag = 0xA003;
    s->type = 4;
    s->count = 1;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = (u32)arg1;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;

    // Sub-table 2 (GPS IFD / other)
    sb->count2 = 0;
    sb->count1++;
    s = &sb->ptr18[sb->count2];
    s->tag = g_021CAE90.tag;
    s->type = g_021CAE90.type;
    s->count = g_021CAE90.count;
    s->field8 = g_021CAE90.field8;
    s->fieldA = g_021CAE90.fieldA;
    s->fieldC = g_021CAE90.fieldC;
    s->field10 = g_021CAE90.field10;
    s->field14 = g_021CAE90.field14;
    func_0208CB10(s->str, g_021CAEC6, 0);
    s->field54 = 0;

    sb->count2++;
    if (g_021CADF0.field18 != 0) {
        s = &sb->ptr18[sb->count2];
        s->tag = 0x1001;
        s->type = 7;
        s->count = g_021CADF0.field18;
        s->field8 = 0;
        s->fieldA = 0;
        s->fieldC = 0;
        s->field10 = 0;
        s->field14 = 0;
        s->field54 = 0;
        sb->count2++;
    }

    if (g_021CADF0.field10 != 0) {
        s = &sb->ptr18[sb->count2];
        s->tag = 0x1002;
        s->type = 7;
        s->count = g_021CADF0.field10;
        s->field8 = 0;
        s->fieldA = 0;
        s->fieldC = 0;
        s->field10 = 0;
        s->field14 = 0;
        s->field54 = 0;
        sb->count2++;
    }

    // Sub-table 3 (Interoperability IFD)
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
    func_02082EA4(s->field18, g_021C88B4, 4);
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

    // Sub-table 4 (Thumbnail IFD1)
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

    sb->count4++;

    if (is_flag) {
        if (sb->count0 == 0) {
            return 0;
        }

        s = &sb->ptr0[sb->count0];
        s->tag = 0x8769;
        s->type = 4;
        s->count = 1;
        sb->count0++;

        if (sb->count2 != 0) {
            if (g_021CADF0.field18 + g_021CAE90.count + g_021CADF0.field10 != 0) {
                struct Slot *m = &sb->ptrC[4];
                m->tag = 0x927C;
                m->type = 7;
                m->count = 6;
                if (g_021CAE90.count != 0) {
                    m->count += 12;
                }
                if (g_021CADF0.field18 != 0) {
                    m->count += 12;
                }
                if (g_021CADF0.field10 != 0) {
                    m->count += 12;
                }
                m->count = g_021CAE90.count + g_021CADF0.field18 + g_021CADF0.field10 + m->count;
            }
        }

        if (sb->count3 != 0) {
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
        sb->field44 = (u32)arg4;
        sb->count4++;
    } else {
        if (sb->count0 == 0) {
            return 0;
        }

        s = &sb->ptr0[sb->count0];
        s->tag = 0x8769;
        s->type = 4;
        s->count = 1;
        sb->count0++;

        if (sb->count2 != 0) {
            if (g_021CADF0.field18 + g_021CAE90.count + g_021CADF0.field10 != 0) {
                struct Slot *m = &sb->ptrC[4];
                m->tag = 0x927C;
                m->type = 7;
                m->count = 6;
                if (g_021CAE90.count != 0) {
                    m->count += 12;
                }
                if (g_021CADF0.field18 != 0) {
                    m->count += 12;
                }
                if (g_021CADF0.field10 != 0) {
                    m->count += 12;
                }
                m->count = g_021CAE90.count + g_021CADF0.field18 + g_021CADF0.field10 + m->count;
            }
        }

        if (sb->count3 != 0) {
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

    g_021CADF0.buffer[g_021CADF0.len++] = 0xFF;
    g_021CADF0.buffer[g_021CADF0.len++] = 0xD8;

    if (is_flag) {
        if (write_exif_ifd_tables(sb, 0, arg3, arg4) == 0) {
            return 0;
        }
    } else {
        if (write_exif_ifd_tables(sb, 1, arg3, arg4) == 0) {
            return 0;
        }
    }

    if ((g_021CADF0.len & 1) == 1) {
        g_021CADF0.buffer[g_021CADF0.len++] = 0;
    }
    return 1;
}
