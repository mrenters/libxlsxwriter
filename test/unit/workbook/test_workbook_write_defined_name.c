/*
 * Tests for the libxlsxwriter library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include "../ctest.h"
#include "../helper.h"

#include "xlsxwriter/workbook.h"

/* Test the _write_defined_name() method. */
CTEST(workbook, write_defined_name) {
    char* got;
    char exp[] = "<definedName name=\"_xlnm.Print_Titles\" localSheetId=\"0\">Sheet1!$1:$1</definedName>";
    FILE* testfile = tmpfile();
    lxw_defined_name defined_name = {0, 0, "_xlnm.Print_Titles", "", "Sheet1!$1:$1", "", "", {NULL, NULL}};


    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_defined_name(workbook, &defined_name);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

