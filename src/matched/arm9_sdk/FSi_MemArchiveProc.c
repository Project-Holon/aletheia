/*
 * function: FSi_MemArchiveProc
 * address:  0x0207A7C4
 * packet:   pkt_0207A7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078530 0x02078530 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   @12205        0x020A84AC data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef struct FSFile FSFile;
typedef struct FSArchive
{
    u8 pad00[4];
    struct FSArchive *next;
} FSArchive;
typedef struct FSDirEntryOut
{
    u32 id;
    unsigned short unk4;
    unsigned short unk6;
    u32 unk8;
    u32 is_directory;
    u32 name_len;
    char name[1];
} FSDirEntryOut;
struct FSFile
{
    u8 pad00[8];
    u32 id;
    u8 pad0c[0x1c];
    FSArchive *cur_arc;
    u8 pad2c[4];
    FSDirEntryOut *entry;
    u32 skip_string;
};
extern char *func_02078530(FSArchive *arc);
extern u32 func_0208CC78(const char *s);
extern int func_0208D7E0(char *dst, const char *fmt, const char *s);

int FSi_MemArchiveProc(FSFile *p_file, u32 cmd)
{
    switch (cmd) {
    case 3: {
        FSDirEntryOut *entry;
        FSArchive *arc;
        char *name;
        arc = p_file->cur_arc;
        entry = p_file->entry;
        if (arc == 0) {
            entry->name_len = 0;
            entry->is_directory = 0;
            return 1;
        }
        name = func_02078530(arc);
        entry->name_len = func_0208CC78(name) + 1;
        entry->is_directory = 1;
        if (p_file->skip_string == 0) {
            func_0208D7E0(entry->name, "%s:", name);
            entry->id = p_file->id;
            entry->unk4 = 0;
            entry->unk6 = 0;
            entry->unk8 = 0;
        }
        p_file->cur_arc = arc->next;
        return 0;
    }
    case 2:
    case 4:
    case 5:
    case 6:
        return 4;
    default:
        return 0x102;
    }
}
