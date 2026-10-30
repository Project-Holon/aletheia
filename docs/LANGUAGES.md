# The language cartridges

Pokémon Black and White were sold in one cartridge per language. The English cartridge
(USA, Europe) is the reference: its layout is `layout/` and every address in `src/game` is an
English Black address. The same source builds the French, German, Italian and Spanish
cartridges of both games, byte-identical to the dumps in [ROMS.md](ROMS.md).

## How much differs

Measured against the English cartridge of the same game:

- The file system has the same 247 files in the same order. 51 to 57 files hold other content
  (text, fonts, graphics with text). The two download-play images carry the language in their
  name.
- The ARM9 module is 64 to 256 bytes shorter, so every overlay loads lower. 4 to 10 overlays
  change size.
- About 140 functions differ. About 40 of them only load the language id. The DSi code is the
  same in every cartridge.
- Black and White differ in the same places in every language, so the version and the
  language are two independent switches.

## The source

`src/game/version.h` defines the switches. The tools pass them from the target
(`tools/targets.py`):

| Name | Meaning |
|---|---|
| `VERSION` | `VERSION_BLACK` (default) or `VERSION_WHITE` |
| `LANGUAGE` | `LANGUAGE_ENGLISH` (default), `_FRENCH` 3, `_ITALIAN` 4, `_GERMAN` 5, `_SPANISH` 7 (`_JAPANESE` 1) |
| `PM_LANG_ID` | the cartridge's language id, stored in the player record, profiles, mail and Wi-Fi data |
| `PM_LANG_MONTH_AS_NAME` | French, Italian and German write a month as its name in dates |
| `PM_LANG_VERSION_KEY` | the Wi-Fi match key: language and version |

A site that differs in one file uses a constant chosen by an `#if LANGUAGE` chain near the top
of the file, with the English value in the `#else`. Most are text positions and widths. A few
are real code: the glyph decoder of French, German and Italian (`gf_font.c`), the species-name
setters of the word set (`wordset.c`), the plural rules of item messages
(`scrcmd_proc_fld.c`), the size of the easy-chat search result list (`pmsi_search.c`) and the
similar-word group count (`pms_word.c`).

## The tools

Every link and ROM tool takes `--target NAME` or `ALETHEIA_TARGET`. Addresses are planned in
English Black and mapped to the target (`tools/white_map.py`): by aligning the two images, and
by the symbol maps of the regions that already link for that target. The data after the code
is generated from the target's own extract with English Black's object structure; tables whose
size changes per language (the easy-chat word lists, some Pokédex arrays) are taken as one block
from the target. `romlink.py --relink` links a region that failed a second time, after the
regions whose addresses it uses have linked.

## Japanese

The Japanese cartridges (`black_ja`, `white_ja`) are an earlier build of the same program. The
source has their sites, but they do not build byte-identical yet ([ROMS.md](ROMS.md)).

- About 95 percent of the functions are the same or differ only in addresses. The rest differ in
  one or two words (line numbers, message archive ids, digit width, the language id 1) or in
  length (older code, Japan-only behaviour, structs with fewer fields).
- Every message has two blocks, kana and kanji. The options menu has a sixth setting for it
  (`CONFIG_GetTextLanguage`, `CONFIG_SetTextLanguage`). A name is 5 characters, not 10.
- A failed check passes the file name, the line and a message string, where the other
  languages pass empty strings. The heap allocations of a file use the same file-name string.

`version.h` has three more names for these sites:

| Name | Meaning |
|---|---|
| `PM_SRC_LINE(english, japanese)` | a source line number (failed checks, heap allocations) |
| `PM_LANG_JA(english, japanese)` | any other value that differs only in Japanese |
| `PM_LANG_HALF_WIDTH_DIGITS` | the digit width of word-set numbers: 0 in Japanese, 1 otherwise |

Data that only Japanese has (the file-name and message strings of failed checks, some tables)
is declared as `<prefix>_ja_<address>` with its Japanese Black address, under
`#if LANGUAGE == LANGUAGE_JAPANESE`. The link places these names in both Japanese targets.
A function that only one language has is guarded with its callers.

The data after the code is placed by content (`tools/jatail.py`): each object of English Black
is searched in the target's tail. An object that the code references is pinned first, by the
literal pools of the functions whose code matches (`white_map.ja_pool_map`).

