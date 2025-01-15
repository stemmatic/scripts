
APPS=do_soln do_ratchet do_anneal do_stemma do_next do_stats do_status

BIN=$(HOME)/bin

APPEXES=$(APPS:%=$(BIN)/%)

all:	$(APPEXES)

$(APPEXES): $(BIN)/%: %
	cp $< $(BIN)/

