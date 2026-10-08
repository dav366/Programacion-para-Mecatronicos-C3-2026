Algoritmo Reto_6_PPMC_20241884
	Definir N, M, L, U Como Entero
	Definir i, j Como Entero
	Definir x, p, d Como Entero
	Definir matriz Como Entero
	Definir eventosFila, impactoFila, rachaFila, inicioRacha Como Entero
	Definir eventosColumna Como Entero
	Definir evento, impacto Como Entero
	Definir rachaActual, inicioActual Como Entero
	Definir filaPrioritaria, columnaDestacada Como Entero
	Definir mejorRacha, mejorImpacto, mejorEventos Como Entero
	Definir valido, hayEventos Como Logico

	Dimension matriz[30,30]
	Dimension eventosFila[30]
	Dimension impactoFila[30]
	Dimension rachaFila[30]
	Dimension inicioRacha[30]
	Dimension eventosColumna[30]

    Leer N, M, L, U

	valido <- Verdadero

	Si N < 1 O N > 30 O M < 1 O M > 30 O L < 0 O U < 0 O L > U O U > 1000 Entonces
		valido <- Falso
	FinSi

	Si valido = Verdadero Entonces

		Para i <- 1 Hasta N Hacer
			Para j <- 1 Hasta M Hacer

				Leer matriz[i,j]

				Si matriz[i,j] < 0 O matriz[i,j] > 1000 Entonces
					valido <- Falso
				FinSi

			FinPara
		FinPara

	FinSi

	Si valido = Falso Entonces

		Escribir "ERROR"
	Sino

		// Inicializar resultados
		Para i <- 1 Hasta N Hacer
			eventosFila[i] <- 0
			impactoFila[i] <- 0
			rachaFila[i] <- 0
			inicioRacha[i] <- 0
		FinPara

		Para j <- 1 Hasta M Hacer
			eventosColumna[j] <- 0
		FinPara

		// Analizar cada fila
		Para i <- 1 Hasta N Hacer

			rachaActual <- 0
			inicioActual <- 0

			Para j <- 1 Hasta M Hacer

				evento <- 0
				impacto <- 0

				// La primera columna no puede ser evento.
				Si j = 1 Entonces

					rachaActual <- 0

				Sino

					x <- matriz[i,j]
					p <- matriz[i,j-1]
					d <- Abs(x - p)

					// Regla del evento:
					// cambio absoluto <= L y valor actual >= U

					Si d <= L Y x >= U Entonces

						evento <- 1
						impacto <- x - U + 1

						eventosFila[i] <- eventosFila[i] + 1
						impactoFila[i] <- impactoFila[i] + impacto
						eventosColumna[j] <- eventosColumna[j] + 1

						Si rachaActual = 0 Entonces
							inicioActual <- j
						FinSi
FinAlgoritmo
