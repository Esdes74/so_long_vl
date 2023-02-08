#!/bin/sh

echo "Norminette :"
# norminette

echo "Compilation :"
make

echo "====================== Tests Correctes ======================"
$1 ./so_long test/Map_Correctes/map_correcte_tests_exit1.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_tests_exit2.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_tests_exit3.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_tests_exit4.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_1.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_2.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_3.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_4.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_5.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_right.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_down.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_left.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_up.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_only_coins.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/map_correcte_bizzare.ber

echo
echo "=============== Tests format incorrectes ===================="
echo
echo "Tests nombre fichier incorrecte"
echo
$1 ./so_long test/Map_Correctes/map_correcte_bizzare.ber test/Map_Correctes/map_correcte_bizzare.ber
echo "###############################################"
$1 ./so_long
echo
echo "Tests nom fichier incorrecte"
echo
$1 ./so_long nom_incorrecte
echo "###############################################"
$1 ./so_long test/Map_Correctes/nom_incorecte.ber
echo "###############################################"
$1 ./so_long test/Map_Correctes/nom_incorecte.berf
echo "###############################################"
$1 ./so_long test/Map_Correctes/nom_incorecte.pdf

echo
echo "================= Tests map incorrectes ====================="
echo
echo "Tests dimensions map"
echo
$1 ./so_long test/Map_Error/map_error_1x1.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_2x2.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_3x3.ber

echo
echo "Tests regles de generations de map pas respectees"
echo
$1 ./so_long test/Map_Error/map_error_multi_exit.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_multijoueur.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_no_conso.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_no_exit.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_no_perso.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_oblong1.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_oblong2.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_only_exit.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_only_wall.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_charactere_not_good.ber

echo
echo "Tests map non faisable"
echo
$1 ./so_long test/Map_Error/map_error_exit_central.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable1.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable2.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable3.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable4.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable5.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable6.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable7.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable8.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_conso_not_reachable9.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable1.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable2.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable3.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable4.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable5.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable6.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable7.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_not_resolvable_exit_not_reachable8.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_between_wall1.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_between_wall2.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_between_wall3.ber
echo "###############################################"
$1 ./so_long test/Map_Error/map_error_not_between_wall4.ber
