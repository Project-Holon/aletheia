# Progress report for ByteMatch

ByteMatch (https://bytematch.dev) shows the progress of a decompilation from an objdiff report that a
GitHub Actions run uploads. This project makes that report locally and commits
it, because CI has no ROM.

## What the report is

`progress/report.json` is the `Report` message of objdiff's
`objdiff-core/protos/report.proto` (encounter/objdiff), in protobuf JSON as
objdiff writes it:

- field names are the proto names (`total_code`, `matched_functions`);
- 64-bit integers (`total_code`, `matched_code`, `complete_code`, `size`,
  `virtual_address`) are JSON strings;
- fields at their default value are left out;
- `version` is 2 (objdiff REPORT_VERSION).

The figures come from `tools/linkstats.py`:

| measure | rule |
|---|---|
| `total_code`, `total_functions` | every non-veneer function of the region listings, sized by its instruction bytes (linkstats rule D) |
| `matched_code`, `matched_functions` | functions with an EXACT or EXACT* match record in `layout/matched/`, or in a unit whose bytes came out identical |
| `complete_code`, `complete_units` | units that linkstats counts as linked (rule L) |
| `total_units` | top-level `src/game` source files (linkstats rule U) |

There is one unit per `src/game` source file, named `<region>/<stem>`, with its
functions (`fuzzy_match_percent` 100 or 0, `metadata.virtual_address`). Code that
no unit covers is in the units `<region>/_no_unit_game` and
`<region>/_no_unit_sdk` (`auto_generated`, not counted in `total_units`). The
categories are `game` and `sdk`: a unit is `sdk` when most of its code bytes are
SDK functions. Each category is the sum of its units.

### Categories

Besides `game` and `sdk`, the report has one category per region group and
kind: `arm9`, `arm9_game`, `arm9_sdk`, `itcm` (and any other autoload block),
`overlays`, `overlays_game`, `overlays_sdk`, `twl`, `twl_game`, `twl_sdk`
(only those with units). Each unit lists all its categories in
`metadata.progress_categories`. Each category carries the code
measures of its units.

The file holds names, sizes, addresses and percentages. It holds no ROM bytes.

## Refresh the report

Run this at each integration commit, after the matching and link checks:

    python tools/progress_report.py

It runs linkstats first (only regions with changed sources are linked again),
then writes `progress/report.json` and prints the headline figures. Commit the
file with the wave. The output is deterministic: the file changes only when a
figure changes.

Options:

- `--no-relink` uses `build/linkstats/cache.json` as it is (fast);
- `--check` exits 1 when the committed file is out of date;
- `--out PATH` writes somewhere else.

## CI

`.github/workflows/progress.yml` runs on each push to `main` (and by hand). It
needs no secrets and no ROM. It:

1. parses the committed report with `objdiff-cli report changes` (objdiff
   v3.8.2), so a malformed report fails the run;
2. uploads `progress/report.json` as the artifact `IRBO_report` (Black) and
   `progress/report_white.json`, renamed `report.json`, as `IRAO_report` (White).

ByteMatch reads the push runs of the default branch. It takes each artifact
whose name matches `<version>_report` and reads the file `report.json` in it.
The versions are `IRBO` and `IRAO`, the game codes of Pokemon Black and White
(USA, Europe). Runs started by hand are not read.

## ByteMatch

The project is registered at https://bytematch.dev/Project-Holon/aletheia.
For a private repository, install the ByteMatch GitHub App (link on the manage
page): GitHub requires authentication to download artifacts. CI that cannot
upload artifacts can send a report to the upload API instead, with a token from
the manage page:

    curl --fail -X POST -H "Authorization: Bearer $BYTEMATCH_TOKEN"       --data-binary @progress/report.json       "https://bytematch.dev/api/v1/projects/Project-Holon/aletheia/reports?version=IRBO&commit=<sha>"

Badges for the READMEs:

    ![Code](https://bytematch.dev/Project-Holon/aletheia.svg?label=Code&measure=matched_code_percent)
    ![Functions](https://bytematch.dev/Project-Holon/aletheia.svg?label=Functions&measure=matched_functions)

Add `&version=IRAO` for White and `&category=<id>` for one category.

## Check the format by hand

objdiff-cli can parse a report:

    objdiff-cli report changes progress/report.json progress/report.json

A run that ends without an error and prints the measures means objdiff (and so
ByteMatch, which reads objdiff reports) accepts the file.
