--Insertion des données dans la table IntervalHorizontalDistance à travers la table earthquekes en utilisant la fonction "case" de postgre

insert into IntervalHorizontalDistance (intervalHorizontalDistance, minHorizontalDistance, maxHorizontalDistance)
select
	case
    	when dmin >= 0 and dmin < 0.6 then '0-0.5'
        when dmin >= 0.6 and dmin < 5 then '0.6-5'
        when dmin >= 5 and dmin < 15 then '5-15'
        when dmin >= 15 and dmin < 30 then '15-30'
        when dmin >= 30 and dmin < 150 then '30-150'
    end as intervalHorizontalDistance,
    min(dmin) as minHorizontalDistance,
    max(dmin) as maxHorizontalDistance
FROM earthquakes where dmin is not null
group by
    case
      	when dmin >= 0 and dmin < 0.6 then '0-0.5'
        when dmin >= 0.6 and dmin < 5 then '0.6-5'
        when dmin >= 5 and dmin < 15 then '5-15'
        when dmin >= 15 and dmin < 30 then '15-30'
        when dmin >= 30 and dmin < 150 then '30-150'
    end;


--Insertion des données dans la table IntervalDamageMillionsDollars à travers la table earthquekes en utilisant la fonction "case" de postgre

insert into IntervalDamageMillionsDollars (IntervalDamageMillionsDollars, minDamageMillionsDollars, maxDamageMillionsDollars)
select
	case
    	when damage_millions_dollars >= 0 and damage_millions_dollars < 100 then '0-100'
        when damage_millions_dollars >= 100 and damage_millions_dollars < 1000 then '100-1000'
        when damage_millions_dollars >= 1000 and damage_millions_dollars < 10000 then '1000-10000'
        when damage_millions_dollars >= 10000 and damage_millions_dollars < 40000 then '10000-40000'
        when damage_millions_dollars >= 40000 then '40000-100000'
    end as IntervalDamageMillionsDollars,
    min(damage_millions_dollars) as minDamageMillionsDollars,
    max(damage_millions_dollars) as maxDamageMillionsDollars
FROM earthquakes where damage_millions_dollars is not null
group by
    case
      	when damage_millions_dollars >= 0 and damage_millions_dollars < 100 then '0-100'
        when damage_millions_dollars >= 100 and damage_millions_dollars < 1000 then '100-1000'
        when damage_millions_dollars >= 1000 and damage_millions_dollars < 10000 then '1000-10000'
        when damage_millions_dollars >= 10000 and damage_millions_dollars < 40000 then '10000-40000'
        when damage_millions_dollars >= 40000 then '40000-100000'
    end;

--Insertion des données dans la table IntervalDeath à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalDeath (IntervalDeath, minDeath, maxDeath)
select
	case
    	when deaths >= 0 and deaths < 1000 then '0-1000'
        when deaths >= 1000 and deaths < 10000 then '100-10000'
        when deaths >= 10000 and deaths < 100000 then '10000-100000'
        when deaths >= 100000 then '100000-850000'
    end as IntervalDeath,
    min(deaths) as minDeath,
    max(deaths) as maxDeath
FROM earthquakes where deaths is not null
group by
    case
      	when deaths >= 0 and deaths < 1000 then '0-1000'
        when deaths >= 1000 and deaths < 10000 then '100-10000'
        when deaths >= 10000 and deaths < 100000 then '10000-100000'
        when deaths >= 100000 then '100000-850000'
    end;

--Insertion des données dans la table IntervalDepth à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalDepth (IntervalDepth, minDepth, maxDepth)
select
	case
		when depth < 0 then '0'
    	when depth >= 0 and depth < 10 then '0-10'
        when depth >= 10 and depth < 50 then '10-50'
        when depth >= 50 and depth < 410 then '50-410'
        when depth >= 410 then '410-700'
    end as IntervalDeath,
    min(depth) as minDepth,
    max(depth) as maxDepth
FROM earthquakes where depth is not null
group by
    case
		when depth < 0 then '0'
      	when depth >= 0 and depth < 10 then '0-10'
        when depth >= 10 and depth < 50 then '10-50'
        when depth >= 50 and depth < 410 then '50-410'
        when depth >= 410 then '410-700'
    end;

--Insertion des données dans la table IntervalGap à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalGap (IntervalGap, minGap, maxGap)
select
	case
    	when gap >= 0 and gap < 70 then '0-70'
        when gap >= 70 and gap < 100 then '10-50'
        when gap >= 100 and gap < 150 then '100-150'
		when gap >= 150 and gap < 200 then '150-200'
		when gap >= 200 and gap < 270 then '200-270'
        when gap >= 270 then '270-370'
    end as IntervalDeath,
    min(gap) as minGap,
    max(gap) as maxGap
FROM earthquakes where gap is not null
group by
    case
		when gap >= 0 and gap < 70 then '0-70'
        when gap >= 70 and gap < 100 then '10-50'
        when gap >= 100 and gap < 150 then '100-150'
		when gap >= 150 and gap < 200 then '150-200'
		when gap >= 200 and gap < 270 then '200-270'
        when gap >= 270 then '270-370'
    end;

--Insertion des données dans la table IntervalHousesDamaged à travers la table earthquekes en utilisant la fonction "case" de postgre	
	
insert into IntervalHousesDamaged (IntervalHousesDamaged, minHousesDamaged, maxHousesDamaged)
select
	case
    	when houses_damaged >= 0 and houses_damaged < 500 then '0-500'
        when houses_damaged >= 500 and houses_damaged < 5000 then '500-5000'
        when houses_damaged >= 5000 and houses_damaged < 50000 then '5000-50000'
		when houses_damaged >= 50000 and houses_damaged < 500000 then '50000-500000'
		when houses_damaged >= 500000 then '500000-5700000'
    end as IntervalHousesDamaged,
    min(houses_damaged) as minHousesDamaged,
    max(houses_damaged) as maxHousesDamaged
FROM earthquakes where houses_damaged is not null
group by
    case
		when houses_damaged >= 0 and houses_damaged < 500 then '0-500'
        when houses_damaged >= 500 and houses_damaged < 5000 then '500-5000'
        when houses_damaged >= 5000 and houses_damaged < 50000 then '5000-50000'
		when houses_damaged >= 50000 and houses_damaged < 500000 then '50000-500000'
		when houses_damaged >= 500000 then '500000-5700000'
    end;	

--Insertion des données dans la table IntervalHousesDestroyed à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalHousesDestroyed (IntervalHousesDestroyed, minHousesDestroyed, maxHousesDestroyed)
select
	case
    	when houses_destroyed >= 0 and houses_destroyed < 5000 then '0-5000'
        when houses_destroyed >= 5000 and houses_destroyed < 500000 then '5000-500000'
		when houses_destroyed >= 500000 then '500000-5000000'
    end as IntervalHousesDestroyed,
    min(houses_destroyed) as minHousesDistroyed,
    max(houses_destroyed) as maxHousesDistroyed
FROM earthquakes where houses_destroyed is not null
group by
    case
		when houses_destroyed >= 0 and houses_destroyed < 5000 then '0-5000'
        when houses_destroyed >= 5000 and houses_destroyed < 500000 then '5000-500000'
		when houses_destroyed >= 500000 then '500000-5000000'
    end;


--Insertion des données dans la table IntervalInjuries à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalInjuries (IntervalInjuries, minInjuries, maxInjuries)
select
	case
    	when injuries >= 0 and injuries < 100 then '0-100'
        when injuries >= 100 and injuries < 500 then '100-500'
        when injuries >= 500 and injuries < 2000 then '500-2000'
		when injuries >= 2000 and injuries < 10000 then '2000-10000'
		when injuries >= 10000 and injuries < 100000 then '10000-100000'
		when injuries >= 100000 then '100000-800000'
    end as IntervalInjuries,
    min(injuries) as minInjuries,
    max(injuries) as maxInjuries
FROM earthquakes where injuries is not null
group by
    case
		when injuries >= 0 and injuries < 100 then '0-100'
        when injuries >= 100 and injuries < 500 then '100-500'
        when injuries >= 500 and injuries < 2000 then '500-2000'
		when injuries >= 2000 and injuries < 10000 then '2000-10000'
		when injuries >= 10000 and injuries < 100000 then '10000-100000'
		when injuries >= 100000 then '100000-800000'
    end;

--Insertion des données dans la table IntervalMissing à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalMissing (IntervalMissing, minMissing, maxMissing)
select
	case
    	when missing >= 0 and missing < 2000 then '0-2000'
        when missing >= 2000 and missing < 40000 then '2000-40000'
		when missing >= 40000 then '40000-45000'
    end as IntervalInjuries,
    min(missing) as minMissing,
    max(missing) as maxMissing
FROM earthquakes where missing is not null
group by
    case
		when missing >= 0 and missing < 2000 then '0-2000'
        when missing >= 2000 and missing < 40000 then '2000-40000'
		when missing >= 40000 then '40000-45000'
    end;

--Insertion des données dans la table IntervalMagnitude à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalMagnitude (IntervalMagnitude, minMagnitude, maxMagnitude)
select
	case
    	when magnitude >= 0 and magnitude < 1 then '0-1'
        when magnitude >= 1 and magnitude < 2 then '1-2'
		when magnitude >= 2 and magnitude < 3 then '2-3'
        when magnitude >= 3 and magnitude < 4 then '3-4'
		when magnitude >= 4 and magnitude < 5 then '4-5'
        when magnitude >= 5 and magnitude < 6 then '5-6'
		when magnitude >= 6 and magnitude < 7 then '6-7'
        when magnitude >= 7 and magnitude < 8 then '7-8'
		when magnitude >= 8 and magnitude < 9 then '8-9'
		when magnitude >= 9 then '9-10'
    end as IntervalMagnitude,
    min(magnitude) as minMagnitude,
    max(magnitude) as maxMagnitude
FROM earthquakes where magnitude is not null
group by
    case
		when magnitude >= 0 and magnitude < 1 then '0-1'
        when magnitude >= 1 and magnitude < 2 then '1-2'
		when magnitude >= 2 and magnitude < 3 then '2-3'
        when magnitude >= 3 and magnitude < 4 then '3-4'
		when magnitude >= 4 and magnitude < 5 then '4-5'
        when magnitude >= 5 and magnitude < 6 then '5-6'
		when magnitude >= 6 and magnitude < 7 then '6-7'
        when magnitude >= 7 and magnitude < 8 then '7-8'
		when magnitude >= 8 and magnitude < 9 then '8-9'
		when magnitude >= 9 then '9-10'
    end;	

--Insertion des données dans la table IntervalSeismicStationNumber à travers la table earthquekes en utilisant la fonction "case" de postgre	

insert into IntervalSeismicStationNumber (IntervalSeismicStationNumber, minSeismicStationNumber, maxSeismicStationNumber)
select
	case
		when nst >= 0 and nst < 100 then '0-100'
        when nst >= 100 and nst < 400 then '100-400'
		when nst >= 400 then '400-900'
    end as IntervalSeismicStationNumber,
    min(nst) as minSeismicStationNumber,
    max(nst) as maxSeismicStationNumber
FROM earthquakes where nst is not null
group by
    case
		when nst >= 0 and nst < 100 then '0-100'
        when nst >= 100 and nst < 400 then '100-400'
		when nst >= 400 then '400-900'
    end;