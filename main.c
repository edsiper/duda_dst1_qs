/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * Duda I/O Examples: 001 Hello World
 * ==================================
 * This example aim to explain how the most basic web service under
 * Duda I/O should work covering the mandatory duda_main() and a minimum
 * callback to be triggered upon HTTP requests.
 */

#include "webservice.h"

DUDA_REGISTER("Duda I/O Examples", "Hello World");

void cb_test(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "This is a test\n");
    response->end(dr, NULL);
}

void cb_main(duda_request_t *dr)
{
    int params;
    char *p;

    response->http_status(dr, 200);

    /* Get the number of parameters in the Query String (qs) */
    params = qs->count(dr);
    response->printf(dr, "Query String count=%i\n", params);

    /* Try to get the value of keys A and B */
    p = qs->get(dr, "A");
    if (p) {
        response->printf(dr, "Value of A=%s\n", p);
    }
    p = qs->get(dr, "B");
    if (p) {
        response->printf(dr, "Value of B=%s\n", p);
    }

    response->end(dr, NULL);
}

int duda_main()
{

    map->static_add("/test", "cb_test");
    map->static_root("cb_main");
    return 0;
}
