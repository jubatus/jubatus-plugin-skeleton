#!/bin/sh

##################################
# example usage of jubaconv
##################################

# Standard input of jubaconv must be a JSON-formatted datum.

cat << '_EOF_' | jubaconv -i datum -o fv -c string_server_config.json
{
  "num_values": {
  },
  "string_values": {
    "data1": "The quick brown fox jumps over the lazy dog.",
    "data2": "Now I see, referees, I won."
  },
  "binary_values": {
  }
}
_EOF_
