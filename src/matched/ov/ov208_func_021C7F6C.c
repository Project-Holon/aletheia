/*
 * function: ZUKAN_DETAIL_FORM_GetModelOffsets
 * address:  0x021C7F6C
 * packet:   pkt_ov208_021C7F6C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021C87C0  0x021C87C0  data
 *   data_021C8854  0x021C8854  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208PoseEnt {
    u32 species;
    u32 form;
    u32 gender;
    u32 fc;
    u32 f10;
    u32 side;
    u32 f18;
    VecF pos[5];
};

extern const VecF data_021C87C0[5];
extern const struct Ov208PoseEnt data_021C8854[15];

void ZUKAN_DETAIL_FORM_GetModelOffsets(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality,
                         u32 side, u32 extra)
{
    u16 k;
    u8 i;

    for (i = 0; i < 5; i++)
        pos[i] = data_021C87C0[i];
    for (k = 0; k < 15; k++) {
        if (species == data_021C8854[k].species && form == data_021C8854[k].form &&
            side == data_021C8854[k].side &&
            (data_021C8854[k].gender == 3 || gender == data_021C8854[k].gender)) {
            for (i = 0; i < 5; i++)
                pos[i] = data_021C8854[k].pos[i];
            return;
        }
    }
}
