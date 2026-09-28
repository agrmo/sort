package haufen;

import baum.binaer.Binaerbaum;
import java.util.ArrayList;

public class Haufen {

    public static int elter(ArrayList<Integer> haufen, int i) {
	return (int) (i / 2);
    }

    public static int linksindex(int i) {
	return 2 * (i + 1) - 1;
    }

    public static int rechtsindex(int i) {
	return 2 * (i + 1);
    }

    public static int links(ArrayList<Integer> haufen, int i) {
	return haufen.get(linksindex(i));
    }

    public static int rechts(ArrayList<Integer> haufen, int i) {
	return haufen.get(rechtsindex(i));
    }

    public static void tausche(ArrayList<Integer> haufen, int i, int j) {
	int izahl = haufen.get(i);
	haufen.set(i, haufen.get(j));
	haufen.set(j, izahl);
    }

    // Geh durch der Liste und baue einen Binärbaum. Der Wert jedes
    // Knotens wird die Zahl in der Liste gezeigt.
    //
    // n.b. die Gleichungen
    // 2i
    // 2i+1
    // fangen mit dem Index 1 an, nicht 0. Also die Gleichungen
    // angefangen mit 0 sind...
    // 2(i+1)-1
    // 2(i+1)+1-1=2(i+1)
    //
    public static Binaerbaum baumvonliste(int[] liste) {

	int n = liste.length;
	ArrayList<Integer> zulaufenindex = new ArrayList<Integer>();
	ArrayList<Binaerbaum> zulaufenbaum = new ArrayList<Binaerbaum>();
	
	Binaerbaum ursprung = new Binaerbaum(liste[0]);
	zulaufenindex.add(0);
	zulaufenbaum.add(ursprung);
	
	while (zulaufenindex.size() > 0) {

	    int ende = zulaufenindex.size() - 1;
	    int zindex = zulaufenindex.remove(ende);
	    Binaerbaum zbaum = zulaufenbaum.remove(ende);

	    int indexlinks = linksindex(zindex);
	    if (indexlinks < n) {
		zbaum.links = new Binaerbaum(liste[indexlinks]);

		zulaufenindex.add(indexlinks);
		zulaufenbaum.add(zbaum.links);
	    }

	    int indexrechts = rechtsindex(zindex);
	    if (indexrechts < n) {
		zbaum.rechts = new Binaerbaum(liste[indexrechts]);

		zulaufenindex.add(indexrechts);
		zulaufenbaum.add(zbaum.rechts);
	    }
	}

	return ursprung;
    }

    // public static int[] listevonbaum(Binaerbaum baum) {}
}
