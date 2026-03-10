# Turbo-ParTool
# PL:
Pakiet programów służących do edytowania pliku `.par` z gry **KnightShift**.

Kompilacja najnowszej wersji wymaga skompilowanej statycznej biblioteki `KsUtils`.<br>
[Link](https://github.com/A-t-l-as/LibKsUtils)<br>

# Export pliku .par za pomocą PARex

**PARex** jest to program służący do eksportu pliku `.par` z
**KnightShift** do postaci katalogu z plikami `.cpp`, które reprezentują
każdą sekcję obiektów pliku `.par`.

## Jak używać?:

1.  Włączamy program.

2.  Wpisujemy nazwę pliku wejściowego wraz z formatem.

3.  Klikamy przycisk enter i czekamy.

4.  Po wyłączeniu okna konsoli wiemy, że program skończył pracę.

Program działa również w trybie ARGC&ARGV. Przykład użycia:

    PARex.exe <nazwa_pliku.par>

## Szybki Export:

Aby w szybki sposób dekompilować plik `.par` należy korzystać z
`EXPORT.ps1` lub `EXPORT.bat`. W celu modyfikacji
argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez
notatnik.\
**Przkład pliku .bat:**

    PARex.exe <nazwapliku.par>

**Przykład pliku .ps1:**

    .\PARex.exe .\<nazwapliku.par>

# Opcjonalna konfiguracja PARex

Plik **PARex.cfg** umożliwia konfigurację sposobu eksportu danych do
plików `.cpp`. Użytkownik może zdecydować, czy wybrane wartości będą
prezentowane jako pojedyncze bity (flagi) o określonych etykietach, czy
w formacie surowym. W przypadku wyłączenia mapowania na flagi, dane
zostaną zapisane jako typ `uint32_t`. Rezygnacja z flagowania pozwala na
znaczące przyspieszenie procesu eksportu oraz skrócenie czasu kompilacji
wygenerowanego kodu. W pliku konfiguracyjnym dostępne są następujące
parametry:

## Prawda:

- YES/Yes/yes

- TRUE/True/true

- 1

## Fałsz:

- NO/No/no

- FALSE/False/false

- 0

# Struktura otrzymanych plików po eksporcie/dekompilacji

Po eksporcie pliku `.par`, otrzymamy katalog w którym znajdują się pliki
`.cpp` reprezentujące sekcje z obiektami. Składnia plików jest w języku
`C++`. Oprócz plików `.cpp` z sekcjami - otrzymujemy również plik
`section_order.txt`, w którym znajduje się kolejność kompilacji plików
sekcji.

# Edycja plików:

- Pliki `.cpp` dobrze jest edytować w programie geany, który w
  estetyczny sposób przedstawia sekcję w postaci drzewka.

- Plik `section_order.txt` to plik, w którym jest kolejność odpowiednich
  sekcji. Przy dodawaniu nowej sekcji należy wpisać nowo dodaną sekcję
  do tego pliku w odpowiednim miejscu.

- Wpisy `count()` oznaczają, że podczas kompilacji, kompilator sam
  policzy ilość sekcji/obiektów w `.par` (jest to bardzo wygodne).
  Jeżeli chcemy na stałę wpisać wartość to możemy ją wpisać zamiast
  `count()` i kompilator to przepuści.

- Aby dodać obiekt - należy skopiować jakiś obiekt i wkleić do środka
  sekcji w odpowiednio wybrane miejsce i pozmieniać dane.

- W takiej kolejności w jakiej jest header i obiekty w danej sekcji, to
  w takiej kolejności zostanie skompilowana sekcja.

- Nazwy zmiennych mogą być dowolne, ale wyjątkami są nazwy
  `number_of_objects` oraz `number_of_sections` - te nazwy są
  zastrzeżone dla kompilatora.

- Program **PARim** czyli kompilator obsługuje komentarze także można je
  zostawiać w plikach.

# Kompilacja plików .cpp do postaci .par przez PARim

**PARim** jest to program, a dokładnie kompilator służacy do kompilacji
całego katalogu z plikami sekcji `.cpp` do postaci `.par`.

## Jak używać?:

1.  Włączamy program.

2.  Wpisujemy nazwe katalogu.

3.  Klikamy enter i za chwilkę powinno się zrobić.

4.  Wyłączenie okna konsoli sygnalizuje zakończenie pracy programu.

Program działa również w trybie ARGC&ARGV. Przykład użycia:

    PARim.exe <nazwa katalogu wejściowego>

## Szybki Import:

Aby w szybki sposób kompilować katalog z plikami `.cpp`, należy
korzystać z `IMPORT.ps1` lub `IMPORT.bat`. W celu modyfikacji
argumentów/konfiguracji należy zedytować plik `.bat/.ps1` przez
notatnik.\
**Przykład pliku .bat:**

    PARim.exe <nazwa katalogu wejściowego>

**Przykład pliku .ps1:**

    .\PARim.exe .\<nazwa katalogu wejściowego>
	
---

# ENG:
A package of programs for editing `.par` files from the game **KnightShift**.

Compiling the latest version requires the compiled static library `KsUtils`.<br>
[Link](https://github.com/A-t-l-as/LibKsUtils)<br>

# Exporting a .par file using PARex

**PARex** is a program used to export a `.par` file from **KnightShift**
into a directory of `.cpp` files, which represent each section of
objects in the `.par` file.

## How to use:

1.  We are turning on the program.

2.  Enter the name of the input file along with its format.

3.  Click the enter button and wait.

4.  When the console window closes, we know that the program has
    finished running.

The program also works in ARGC&ARGV mode. Example of use:

    PARex.exe <par_file_name.par>

## Quick Export:

To quickly decompile a `.par` file, use `EXPORT.ps1` or `EXPORT.bat`. To
modify arguments/configuration, edit the `.bat/.ps1` file using
Notepad.\
**Example of a .bat file:**

    PARex.exe <filename.par>

**Example of a .ps1 file:**

    .\PARex.exe .\<filename.par>

# Optional PARex configuration

The **PARex.cfg** file allows you to configure how data is exported to
`.cpp` files. You can decide whether the selected values will be
presented as individual bits (flags) with specific labels or in raw
format. If flag mapping is disabled, the data will be saved as
`uint32_t`. Disabling flagging significantly speeds up the export
process and reduces the compilation time of the generated code. The
following parameters are available in the configuration file:

## True:

- YES/Yes/yes

- TRUE/True/true

- 1

## False:

- NO/No/no

- FALSE/False/false

- 0

# Structure of files obtained after export/decompilation

After exporting the `.par` file, we will receive a directory containing
`.cpp` files representing sections with objects. The syntax of the files
is in `C++`. In addition to the `.cpp` files with sections, we also
receive a `section_order.txt` file, which contains the order in which
the section files are compiled.

# Editing files:

- It is a good idea to edit `.cpp` files in Geany, which presents the
  section in an aesthetic tree structure.

- The `section_order.txt` file contains the order of the relevant
  sections. When adding a new section, enter the newly added section
  into this file in the appropriate place.

- `count()` entries mean that during compilation, the compiler will
  count the number of sections/objects in `.par` (which is very
  convenient). If we want to enter a fixed value, we can enter it
  instead of `count()` and the compiler will accept it.

- To add an object, copy an existing object, paste it into the center of
  the section in the appropriate place, and change the data.

- The section will be compiled in the same order as the header and
  objects in a given section.

- Variable names can be arbitrary, but the names `number_of_objects` and
  `number_of_sections` are exceptions - these names are reserved for the
  compiler.

- The **PARim** program, i.e., the compiler, supports comments, so you
  can also leave them in files.

# Compiling .cpp files into .par files using PARim

**PARim** is a program, or more precisely a compiler used to compile an
entire directory of `.cpp` files into `.par` files.

## How to use:

1.  We are turning on the program.

2.  Enter the name of the directory.

3.  Press enter and it should be done in a moment.

4.  Closing the console window signals the end of the program.

The program also works in ARGC&ARGV mode. Example of use:

    PARim.exe <input directory name>

## Quick Import:

To quickly compile a directory with `.cpp` files, use `IMPORT.ps1` or
`IMPORT.bat`. To modify arguments/configuration, edit the `.bat/.ps1`
file with Notepad.\
**Example of a .bat file:**

    PARim.exe <input directory name>

**Example of a .ps1 file:**

    .\PARim.exe .\<input directory name>
