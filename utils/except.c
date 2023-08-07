#include <stdlib.h>

#include "except.h"

const end_error END_ERROR_NONE = {0, NULL, false};
const end_error END_ERROR_DEFAULT = {-1, "An unknown error occurred.", false};
const end_error END_ERROR_INVALID_ARGUMENT = {-2, "An invalid argument was passed.", false};
const end_error END_ERROR_DIVISION_BY_ZERO = {-3, "A division by zero occurred.", false};

static end_error end_error_current;
static int end_error_current_id = 0;

void end_error_throw(end_error error)
{
     if (end_error_current.message_needs_free) {
          free(end_error_current.message);
     }
     end_error_current = error;
     end_error_current_id += 1;
}

end_error end_error_get(void)
{
     return end_error_current;
}

int end_error_get_id(void)
{
     return end_error_current_id;
}
