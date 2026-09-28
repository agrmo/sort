package sortieren.haufen;

import java.util.Arrays;

// sortieren.haufen.Main

public class Main {
    static void beispieleins() {

	int[] unsortiert = {9,5,1,-1,51,521,19,2,6,111};

	int[] sortiert = Haufensortieren.sortiere(unsortiert);

	System.out.println(Arrays.toString(sortiert));
    }

    public static void main(String[] args) {
	beispieleins();
    }
}
