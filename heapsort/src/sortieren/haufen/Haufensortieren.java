package sortieren.haufen;

import haufen.klein.Kleinhaufen;

public class Haufensortieren {
    public static int[] sortiere(int[] unsortiert) {

	int sortiert[] = new int[unsortiert.length];
	Kleinhaufen haufen = new Kleinhaufen();

	int fuegeindex = 0;
	while (fuegeindex < unsortiert.length) {

	    haufen.fuege(unsortiert[fuegeindex]);
	    fuegeindex += 1;
	}

	int sortiertindex = 0;
	while (haufen.liste.size() > 0) {
	    
	    sortiert[sortiertindex] = haufen.liste.get(0);
	    sortiertindex += 1;
	    haufen.loesche(0);
	}

	return sortiert;
    }
}
