from random import randrange

# Simple recursive quicksort.
def quicksort(liste):

    if len(liste) <= 1:
        return liste
    
    elif len(liste) == 2:
        if liste[0] < liste[1]:
            return liste
        else:
            return [liste[1], liste[0]]
    else:
        # Drehpunkt trennt die Liste.
        drehpunkt = randrange(0, len(liste) - 1)

        # Zahl des Drehpunkts.
        drehpunkt_zahl = liste[drehpunkt]

        klein = []
        gross = []

        for zahl in liste:
            if (zahl < drehpunkt_zahl):
                klein.append(zahl)
            else:
                gross.append(zahl)

        klein_geordnet = quicksort(klein)
        gross_geordnet = quicksort(gross)

        klein_geordnet.extend(gross_geordnet)

        return klein_geordnet
    
